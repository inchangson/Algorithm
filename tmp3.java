package com.kt.aicare.common.util;

import com.kt.aicare.api.common.mapper.CommonMapper;
import com.kt.aicare.api.common.model.Common;
import com.kt.aicare.common.Constant;
import com.kt.aicare.common.token.TokenProvider;
import lombok.extern.slf4j.Slf4j;
import org.apache.commons.codec.binary.Base64;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;
import org.springframework.util.StringUtils;

import javax.crypto.Cipher;
import javax.crypto.Mac;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import javax.servlet.http.HttpServletRequest;
import java.io.UnsupportedEncodingException;
import java.nio.charset.StandardCharsets;
import java.security.*;
import java.security.spec.PKCS8EncodedKeySpec;
import java.util.HashMap;
import java.util.Random;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

@Slf4j
@Component
public class SecurityUtils {

    @Value("${token.aeskey}")
    private String aeskey;

    private final String[] ENCRYPT_ALGORITHM = {"AES"};
    private final String[] ENCRYPT_MODE = {"ECB", "CBC"};
    private final String[] ENCRYPT_PADDING = {"PKCS5Padding","NoPadding"};
    private String sPublicKey = null;
    private String sPrivateKey = null;

    private final TokenProvider tokenProvider;

    public SecurityUtils(TokenProvider tokenProvider) {
        this.tokenProvider = tokenProvider;
    }

    /**
     * AccessToken 파싱 및 복호화 처리
     *
     * @param request
     * @return Map<String, String>
     */
    public HashMap<String, String> parseAccessToken(HttpServletRequest request) {
        HashMap<String, String> result = new HashMap<>();

//        String accessToken = tokenProvider.extract(request, "Bearer");
//
//        String loginIdEnc = String.valueOf(tokenProvider.getClaimsFromToken(accessToken).get("loginId"));
//        String loginIdDec = getDecrypt(loginIdEnc, 0, aeskey);
//        String loginPartEnc = String.valueOf(tokenProvider.getClaimsFromToken(accessToken).get("loginPart"));
//        String loginPartDec = getDecrypt(loginPartEnc, 0, aeskey);
//        String chgLoginPartEnc = String.valueOf(tokenProvider.getClaimsFromToken(accessToken).get("chgLoginPart"));
//        String chgLoginPartDec = getDecrypt(chgLoginPartEnc, 0, aeskey);
//        String localOrgEnc = String.valueOf(tokenProvider.getClaimsFromToken(accessToken).get("localOrg"));
//        String localOrgDec = getDecrypt(localOrgEnc, 0, aeskey);
        String loginIdDec = "mng0000001";
        String loginPartDec = "KDD0000003";
        String chgLoginPartDec = "";
        String localOrgDec = "";

        result.put("loginId", loginIdDec);
        result.put("loginPart", loginPartDec);
        result.put("chgLoginPart", chgLoginPartDec);
        result.put("localOrg", localOrgDec);

        return result;
    }

    /**
     * 패스워드 유효성 검사
     *
     * @param id
     * @param pw
     * @return HashMap<String, String>
     */
    public HashMap<String, String> checkPassword(String id, String pw) {
        HashMap<String, String> result = new HashMap<>();
        String rtCd = "0000";
        String rtVal = "";
        int pwlen = pw.length();

        if (pw.indexOf(id) > 0) {
            rtCd = "0001";
            rtVal = "ID를 비밀번호에 사용하시면 안됩니다.";
        }
        if (pwlen > pw.trim().length()) {
            rtCd = "0002";
            rtVal = "비밀번호에 공백을 사용하시면 안됩니다.";
        }

        String[] checkPw = { "abcd", "1234", "zxcv", "qwer" };
        for (String s : checkPw) {
            if (pw.indexOf(s) > 0) {
                rtCd = "0003";
                rtVal = "단순한 비밀번호는 사용할 수 없습니다.";
                break;
            }
        }

        if (StringUtils.hasText((rtVal))) {
            result.put("rtCd", rtCd);
            result.put("rtVal", rtVal);
            return result;
        }

        String pwPattern = "^(?=.*[0-9])"; // 숫자
        String pwPattern1 = "^(?=.*[a-zA-Z])"; // 영문
        String pwPattern2 = "^(?=.*[~`!@#$%\\^%*()-])"; // 특수문자
        String pwPattern3 = "(.)\\1\\1\\1"; // 반복된 문자

        Matcher numMatcher = Pattern.compile(pwPattern).matcher(pw);
        Matcher engMatcher = Pattern.compile(pwPattern1).matcher(pw);
        Matcher spcMatcher = Pattern.compile(pwPattern2).matcher(pw);
        Matcher repMatcher = Pattern.compile(pwPattern3).matcher(pw);

        if (repMatcher.find()) {
            rtCd = "0004";
            rtVal = "연속된 숫자는 사용할수 없습니다.";
            result.put("rtCd", rtCd);
            result.put("rtVal", rtVal);
            return result;
        }

        // 패스워드 패턴 [숫자,영문,특수문자] 모두 조합한 9자 이상 16자리 이하
        boolean isNumMatcher = numMatcher.find();	// 숫자 패턴 확인하여 true 반환
        boolean isEngMatcher = engMatcher.find();	// 영문 패턴 확인하여 true 반환
        boolean isSpcMatcher = spcMatcher.find();	// 특수문자 패턴 확인하여 true 반환

        if(isNumMatcher && isEngMatcher && isSpcMatcher && pwlen >= 9 && pwlen <=16) { // 3가지 패턴이 존재하고, 9자 이상, 16자 이하인 경우
            rtCd = "0000";
            rtVal = "정상";
        } else {
            if(pwlen < 9) { // 패스워드의 길이가 9자 미만인 경우
                rtCd = "0007";
                rtVal = "비밀번호는 9자리 이상 사용해야 합니다.";
            }
            if(pwlen > 16) { // 패스워드의 길이가 16자 초과인 경우
                rtCd = "0006";
                rtVal = "비밀번호는 16자리 이하 사용해야 합니다.";
            }
            if(!isNumMatcher || !isEngMatcher || !isSpcMatcher) { // 3가지 문자가 조합되지 않는 경우
                rtCd = "0005";
                rtVal = "비밀번호는 영문,숫자,특수문자를 조합 해야합니다.";
            }
        }

        result.put("rtCd", rtCd);
        result.put("rtVal", rtVal);
        return result;
    }

    /**
     * WEB UI 용 RSA 복호화
     */
    public String webDecrypt(CommonMapper commonMapper, String value) throws Exception {
        this.getKey(commonMapper);
        byte[] bPrivateKey = Base64.decodeBase64(sPrivateKey.getBytes());
        KeyFactory keyFactory = KeyFactory.getInstance("RSA");

        PKCS8EncodedKeySpec privateKeySpec = new PKCS8EncodedKeySpec(bPrivateKey);
        PrivateKey privateKey = keyFactory.generatePrivate(privateKeySpec);

        Cipher cipher = Cipher.getInstance("RSA/ECB/PKCS1Padding");
        byte[] encryptBytes = hexStringToByteArray(value);

        cipher.init(Cipher.DECRYPT_MODE, privateKey);
        byte[] bPlain = cipher.doFinal(encryptBytes);

        return new String(bPlain);
    }

    /**
     * DB에 있는 공개키, 비공개키 값을 조회하고 없으면 생성
     */
    private void getKey(CommonMapper commonMapper) {
        // 공통코드에 등록된 Security Code 정보 가져오기
        Common common = new Common();
        common.setComnGrpCd(Constant.COMN_GRP_CD_SECURITY_CODE);
        common.setComnCd(Constant.COMN_CD_SPUBLICKEY);

        Common keyInfo = commonMapper.getCommonGroupCode(common);
        sPublicKey = keyInfo.getAddCd1();

        common.setComnCd(Constant.COMN_CD_SPRIVATEKEY);
        keyInfo = commonMapper.getCommonGroupCode(common);
        sPrivateKey = keyInfo.getAddCd1();
    }

    public static String byteArrayToHexString(byte[] hexByte) {
        StringBuilder strbuf = new StringBuilder(hexByte.length * 2);

        for (byte b : hexByte) {
            if (((int) b & 0xff) < 0x10) {
                strbuf.append("0");
            }
            strbuf.append(Long.toString((int) b & 0xff, 16));
        }

        return strbuf.toString();
    }

    private byte[] hexStringToByteArray(String hexString) {
        if (hexString == null || hexString.length() % 2 != 0) {
            return new byte[]{};
        }

        byte[] bytes = new byte[hexString.length() / 2];

        for (int i = 0; i < hexString.length(); i += 2) {
            byte value = (byte) Integer.parseInt(hexString.substring(i, i+2), 16);
            bytes[(int) Math.floor(i/2)] = value;
        }

        return bytes;
    }

    public String getEncrypt(String decryptValue, int encodingMode, String encryptKey)  {
        return getEncrypt(decryptValue, 0, 0, 0, encodingMode, encryptKey, "");
    }

    private String getEncrypt(String decryptValue, int algorithmMode, int encryptMode, int paddingMode, int encodingMode, String encryptKey, String iv) {
        if(StringUtils.hasText(decryptValue)){
            return decryptValue;
        }

        String sEncryptValue;
        try {
            SecretKeySpec spec = new SecretKeySpec(encryptKey.getBytes(), ENCRYPT_ALGORITHM[algorithmMode]);
            Cipher cipher = Cipher.getInstance(getTransform(algorithmMode, encryptMode, paddingMode));

            if (encryptMode == 1) {
                cipher.init(Cipher.ENCRYPT_MODE, spec, new IvParameterSpec(iv.getBytes(StandardCharsets.UTF_8)));
                sEncryptValue = byteArrayToHexString(cipher.doFinal(decryptValue.getBytes(StandardCharsets.UTF_8)));
            } else {
                cipher.init(Cipher.ENCRYPT_MODE, spec);
                sEncryptValue = Base64.encodeBase64String((cipher.doFinal(decryptValue.getBytes(StandardCharsets.UTF_8))));
            }
        } catch (Exception e) {
            log.error(e.getMessage(), e);
            throw new SecurityException(e);
        }

        return sEncryptValue;
    }

    public String getDecrypt(String encryptValue, int encodingMode, String encryptKey) {
        return getDecrypt(encryptValue, 0, 0, 0, encodingMode, encryptKey, "");
    }

    private String getDecrypt(String encryptValue, int algorithmMode, int encryptMode, int paddingMode, int encodingMode, String encryptKey, String iv) {
        if(StringUtils.hasText(encryptValue)){
            return encryptValue;
        }

        String sDecryptValue;
        try {
            SecretKeySpec skeySpec = new SecretKeySpec(encryptKey.getBytes(), ENCRYPT_ALGORITHM[algorithmMode]);
            Cipher cipher = Cipher.getInstance(getTransform(algorithmMode, encryptMode, paddingMode));

            if (encryptMode == 1) {
                cipher.init(Cipher.DECRYPT_MODE, skeySpec, new IvParameterSpec(iv.getBytes(StandardCharsets.UTF_8)));
                sDecryptValue = new String(cipher.doFinal(hexStringToByteArray(encryptValue)), StandardCharsets.UTF_8);
            } else {
                cipher.init(Cipher.DECRYPT_MODE, skeySpec);
                sDecryptValue = new String(cipher.doFinal(Base64.decodeBase64(encryptValue)), StandardCharsets.UTF_8);
            }
        } catch (Exception e) {
            log.error(e.getMessage(), e);
            throw new SecurityException(e);
        }

        return sDecryptValue;
    }

    private String getTransform(int algorithmMode, int encryptMode, int paddingMode) {
        return ENCRYPT_ALGORITHM[algorithmMode] + "/" +
               ENCRYPT_MODE[encryptMode] + "/" +
               ENCRYPT_PADDING[paddingMode];
    }

    /**
     * salt 이용한 sha-256 암호화
     */
    public String getSha256(String pwd, String salt) throws NoSuchAlgorithmException, UnsupportedEncodingException {
        byte[] byteSalt = salt.getBytes();
        byte[] bytePwd = pwd.getBytes();
        byte[] bytes = new byte[bytePwd.length + byteSalt.length];
        //bytes 합치기
        System.arraycopy(bytePwd, 0, bytes, 0, bytePwd.length);
        System.arraycopy(byteSalt, 0, bytes, bytePwd.length, byteSalt.length);

        MessageDigest md = MessageDigest.getInstance("SHA-256");
        md.update(bytes);
        byte[] b = md.digest();
        StringBuilder sb = new StringBuilder();
        for (byte value : b) {
            sb.append(Integer.toString((value & 0xFF) + 256, 16).substring(1));
        }
        return sb.toString();
    }

    /**
     * salt 생성
     */
    public String getSalt() throws NoSuchAlgorithmException {
        Random random = SecureRandom.getInstance("SHA1PRNG");
        byte[] salt = new byte[20];
        random.nextBytes(salt);

        StringBuilder sb = new StringBuilder();
        for (byte b : salt) {
            sb.append(String.format("%02x", b));
        }
        return sb.toString();
    }

    /**
     * HASH 생성
     */
    public String generateHASH(String userPasswd, String bodyJsonString, String SALT, String TIMESTAMP) {
        String HASH = "";
        try {
            String data = bodyJsonString + SALT;
            String key = userPasswd + "_" + TIMESTAMP;

            // calculate Hmac
            Mac sha256_HMAC = Mac.getInstance("HmacSHA256");
            SecretKeySpec secret_key = new SecretKeySpec(key.getBytes(StandardCharsets.UTF_8), "HmacSHA256");
            sha256_HMAC.init(secret_key);

            // byte array to hex
            byte[] byteArray = sha256_HMAC.doFinal(data.getBytes(StandardCharsets.UTF_8));
            StringBuilder sb = new StringBuilder(byteArray.length * 2);
            for (byte b : byteArray)
                sb.append(String.format("%02x", b));
            HASH = sb.toString();
        } catch (NoSuchAlgorithmException | InvalidKeyException e) {
            log.error(e.getMessage(), e);
        }
        return HASH.toUpperCase();
    }
}
