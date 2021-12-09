#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, int> genre_cnt;
    map<string, map<int, int>> music_list;
    
    for(int i = 0 ; i < genres.size(); ++i)
    {
        genre_cnt[genres[i]] += plays[i];
        music_list[genres[i]][i] = plays[i];
    }
    
    map<int, string> sorted_genre;
    
    //모든 장르 재생 횟수 다르니 가능
    for(const auto & [key, val] : genre_cnt)
    {
        sorted_genre[val] = key;
    }
    
    for(auto iter = sorted_genre.rbegin(); iter != sorted_genre.rend(); ++iter)
    {
        string gen = iter->second;
        
        int top_songs[3][2] = {0, };
        for(auto iter = music_list[gen].begin();
           iter != music_list[gen].end(); ++iter)
        {
            for(int idx = 0; idx < 2; ++idx)
            {
                if(iter->second > top_songs[idx][1])
                {
                    top_songs[idx + 1][0] = top_songs[idx][0];
                    top_songs[idx + 1][1] = top_songs[idx][1];                    
                    top_songs[idx][0] = iter->first;
                    top_songs[idx][1] = iter->second;
                    break;
                }
            }
        }            
        for(int idx = 0; idx < 2; ++idx)
        {
            if(top_songs[idx][1] != 0)
                answer.push_back(top_songs[idx][0]);
        }
    }
    
    return answer;
}
