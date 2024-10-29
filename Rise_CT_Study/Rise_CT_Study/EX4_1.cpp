#include <iostream>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

// addr => 배열상에서 각 원소의 주소 (몇 번째 인지), 리스트 상에서 2번째 원소라는 것이 아님

// num => 새로 할당할 원소의 데이터

// unused => 현재 사용되지 않는 인덱스, 
// 즉 새로운 원소가 들어갈 수 있는 인덱스이고 원소가 추가된 이후에는 1씩 증가

void insert(int addr, int num) {

    // 코드의 작동 원리 
    // : 새로운 원소를 생성해 왼쪽과 오른쪽 팔이 향할 방향을 결정, 서로 손잡을 노드와 연결해주려고 한다.

    // step 1. 우선 새로운 원소의 몸통을 생성한다.
    // 1. 새로운 원소를 생성 (새 주소에 값을 할당하면 그것이 원소의 생성과 같음)
    dat[unused] = num;

    // step 2. <기존 노드> - <새 노드> - <기존 노드의 다음 노드> 순서를 유지하도록 
    // 팔이 향할 방향을 결정해 연결을 설정한다.

    // 2. 새 원소의 pre 값에 삽입할 위치의 주소를 대입
    // 이렇게 하면 기존에 존재하던 addr에 해당하는 노드와 새로 삽입된 노드쪽으로 손을 뻗으면서
    // 새 노드는 addr 노드 바로 뒤에 위치하게 된다.
    pre[unused] = addr;

    // 3. 새 원소의 nxt 값에 삽입할 위치의 nxt 값을 대입
    // 새 노드의 다음 노드를 기존 addr의 다음 노드로 지정하여 그쪽으로 손을 뻗는다.
    nxt[unused] = nxt[addr];
     
    // step 3. 손을 뻗을 방향이 확정되었으므로 기존의 addr 노드의 뒤에 
    // 새 노드가 위치하도록 하여 손을 잡게 만들어 최종 연결을 마친다.
    
    // 4. 삽입할 위치의 nxt 값과 삽입할 위치의 다음 원소의 pre 값을 새 원소로 변경
    // 맨 마지막 원소의 뒤에 새 원소를 추가하는 상황이라면 "삽입할 위치의 다음 원소"가 존재하지 않음
    // 그런데도 pre[nxt[addr]] = unused; 로 써버리면 nxt[addr]이 -1이 되므로 pre[-1]에 접근할 수 있음 
    // 그래서 nxt[addr]가 -1이 아닐 때에만 pre[nxt[addr]]에 unused를 대입하도록 함.
    if (nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;

    // 5. unused를 1 증가시켜 다음에 insert 연결을 할 때 지금 추가된 노드 다음의 인덱스에서 시작하도록 한다.
    unused++;

}

void erase(int addr) 
{
    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

void traverse() {
    int cur = nxt[0];
    while (cur != -1) {
        cout << dat[cur] << ' ';
        cur = nxt[cur];
    }
    cout << "\n\n";
}

void insert_test() {
    cout << "****** insert_test *****\n";
    insert(0, 10); // 10(address=1)
    traverse();
    insert(0, 30); // 30(address=2) 10
    traverse();
    insert(2, 40); // 30 40(address=3) 10
    traverse();
    insert(1, 20); // 30 40 10 20(address=4)
    traverse();
    insert(4, 70); // 30 40 10 20 70(address=5)
    traverse();
}

void erase_test() {
    cout << "****** erase_test *****\n";
    erase(1); // 30 40 20 70
    traverse();
    erase(2); // 40 20 70
    traverse();
    erase(4); // 40 70
    traverse();
    erase(5); // 40
    traverse();
}

int main(void) {
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);
    insert_test();
    erase_test();
}