#include <iostream>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

// addr => �迭�󿡼� �� ������ �ּ� (�� ��° ����), ����Ʈ �󿡼� 2��° ���Ҷ�� ���� �ƴ�

// num => ���� �Ҵ��� ������ ������

// unused => ���� ������ �ʴ� �ε���, 
// �� ���ο� ���Ұ� �� �� �ִ� �ε����̰� ���Ұ� �߰��� ���Ŀ��� 1�� ����

void insert(int addr, int num) {

    // �ڵ��� �۵� ���� 
    // : ���ο� ���Ҹ� ������ ���ʰ� ������ ���� ���� ������ ����, ���� ������ ���� �������ַ��� �Ѵ�.

    // step 1. �켱 ���ο� ������ ������ �����Ѵ�.
    // 1. ���ο� ���Ҹ� ���� (�� �ּҿ� ���� �Ҵ��ϸ� �װ��� ������ ������ ����)
    dat[unused] = num;

    // step 2. <���� ���> - <�� ���> - <���� ����� ���� ���> ������ �����ϵ��� 
    // ���� ���� ������ ������ ������ �����Ѵ�.

    // 2. �� ������ pre ���� ������ ��ġ�� �ּҸ� ����
    // �̷��� �ϸ� ������ �����ϴ� addr�� �ش��ϴ� ���� ���� ���Ե� ��������� ���� �����鼭
    // �� ���� addr ��� �ٷ� �ڿ� ��ġ�ϰ� �ȴ�.
    pre[unused] = addr;

    // 3. �� ������ nxt ���� ������ ��ġ�� nxt ���� ����
    // �� ����� ���� ��带 ���� addr�� ���� ���� �����Ͽ� �������� ���� ���´�.
    nxt[unused] = nxt[addr];
     
    // step 3. ���� ���� ������ Ȯ���Ǿ����Ƿ� ������ addr ����� �ڿ� 
    // �� ��尡 ��ġ�ϵ��� �Ͽ� ���� ��� ����� ���� ������ ��ģ��.
    
    // 4. ������ ��ġ�� nxt ���� ������ ��ġ�� ���� ������ pre ���� �� ���ҷ� ����
    // �� ������ ������ �ڿ� �� ���Ҹ� �߰��ϴ� ��Ȳ�̶�� "������ ��ġ�� ���� ����"�� �������� ����
    // �׷����� pre[nxt[addr]] = unused; �� ������� nxt[addr]�� -1�� �ǹǷ� pre[-1]�� ������ �� ���� 
    // �׷��� nxt[addr]�� -1�� �ƴ� ������ pre[nxt[addr]]�� unused�� �����ϵ��� ��.
    if (nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;

    // 5. unused�� 1 �������� ������ insert ������ �� �� ���� �߰��� ��� ������ �ε������� �����ϵ��� �Ѵ�.
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