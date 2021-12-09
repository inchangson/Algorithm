#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef struct car{
    //����
    int _weight;
    //���� �ð�
    int _clock;
}car;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int truck_cnt = truck_weights.size();
    int sec = 0;
    int rp = 0;
    int cur_total_weight = 0;
    int completed = 0;
    queue<car> bridge;
    
    while(completed != truck_cnt){
        ++sec;     
        //�ڵ����� ����.       
        if(!bridge.empty() && (sec - bridge.front()._clock == bridge_length))
        {
            cur_total_weight -= bridge.front()._weight;
            bridge.pop();
            ++completed;
            //�� ������
            if(completed == truck_cnt)
            {
                break;
            }
        }   
        //�ٸ��� �ڵ��� �ִ´�.
        if(truck_weights[rp] + cur_total_weight <= weight){
            bridge.push({truck_weights[rp], sec});
            cur_total_weight += truck_weights[rp];
            ++rp;
        }
    }
    
    return sec;
}
