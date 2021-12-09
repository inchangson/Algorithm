#include <string>
#include <vector>
#include <cstdio>

using namespace std;

typedef struct docu{
    int priority;
    bool is_target;
    struct docu* prev;
    struct docu* next;
}docu;

docu* g_tail;
docu* g_head;

void queue_push(int p, bool t){
    docu* node = new docu;
    node->priority = p;
    node->is_target = t;
    node->next = NULL;
    if(g_head == NULL){
        node->prev = NULL;
        g_head = g_tail = node;
    }
    else{
        node->prev = g_tail;
        g_tail->next = node;
        g_tail = node;
    }
}

void queue_pop(){
    if(g_head == NULL)  return;
    if(g_tail == g_head){
        delete g_head;
        g_tail = g_head = NULL;
    }
    else{
        docu* tmp = g_head;
        g_head = g_head->next;
        g_head->prev = NULL;   
        delete tmp;
    }
}

void pop_all(){
    while(g_head){
        queue_pop();
    }
}

void print_all(){
    docu* node = g_tail;
    int idx = 0;
    while(node && idx < 20){
        ++idx;
        printf("(%d, %d) ", node->priority, node->is_target);
        node = node->prev;
    }
    printf("\n");
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    g_tail = g_head = NULL;
    for(int idx = 0; idx < priorities.size(); ++idx){
        queue_push(priorities[idx], idx == location);
    }
    print_all();
    int cnt = 0;
    bool is_bigger_exist;
    while(g_head){
        is_bigger_exist = false;
        docu* node = g_head->next;
        while(node){
            if(g_head->priority < node->priority){
                is_bigger_exist = true;
                break;
            }
            node = node->next;
        }
        if(is_bigger_exist){
            queue_push(g_head->priority, g_head->is_target);
        }
        else{
            ++cnt;
            if(g_head->is_target){
                answer = cnt;
                break;
            }
        }
        queue_pop();
    }
    pop_all();
    return answer;
}
int main(){
	vector<int> input_data1 { 1, 1, 1, 9 , 1, 1};
	int data2 = 0;
	printf("%d\n", solution(input_data1, data2));
	return 0;
}
