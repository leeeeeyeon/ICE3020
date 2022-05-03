#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include<sstream>
#include <vector>

using namespace std;
 
#define EMPTY_STRING ""
 
struct Node
{
    string ch; // 문자 값
    int freq; // 빈도수
    Node *left, *right; // 왼쪽, 오른쪽 자식 노드
};
 
// 새로운 노드 생성
Node* getNode(string ch, int freq, Node* left, Node* right)
{
    Node* node = new Node();
 
    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;
 
    return node;
}
 
// 우선순위 큐 정렬을 위한 구조체
struct comp
{
    bool operator()(const Node* l, const Node* r) const
    {
        // 빈도수를 기준으로 최소 힙 정렬
        return l->freq > r->freq;
    }
};
 
// 허프만 트리가 단일 노드만 포함하는지 확인하는 함수
bool isLeaf(Node* root) {
    return root->left == nullptr && root->right == nullptr;
}
 
void encode(Node* root, string str, unordered_map<string, string> &huffmanCode)
{
    if (root == nullptr) {
        return;
    }
 
    // 리프노드를 찾는다
    if (isLeaf(root)) {
        huffmanCode[root->ch] = (str != EMPTY_STRING) ? str : "1";
    }
    // 왼쪽은 0, 오른쪽은 1
    // 재귀 함수를 이용하여 트리를 순회하며 정보를 더한다.
    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}
 
// 허프만 트리를 만드는 함수
void buildHuffmanTree(string text) {
    if (text == EMPTY_STRING) {
        return;
    }
 
    // 빈도수를 count하여 배열에 저장
    unordered_map<string, int> freq;
    
    istringstream ss(text);
    string stringBuffer;
    vector<string> x;
    x.clear();
    while (getline(ss, stringBuffer, ' ')){
        x.push_back(stringBuffer);
    }
    
    for (string ch : x) {
        freq[ch]++;
    }
 
    // 우선순위 큐 생성
    priority_queue<Node*, vector<Node*>, comp> pq;
 
    // 우선 순위 큐에 삽입
    for (auto pair: freq) {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }
 
    while (pq.size() != 1)
    {
        // 빈도수가 작은 순으로 2개를 꺼낸다
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
 
        // 새로운 노드를 만들어 다시 우선순위 큐에 삽입한다
        int sum = left->freq + right->freq;
        pq.push(getNode("\0", sum, left, right));
    }
 
    // 위 작업을 마치면 우선순위 큐에는 한 가지 원소만 남는데, 그것이 트리의 루트 노드가 된다
    Node* root = pq.top();
 
    // 허프만 트리를 순회하며 결과 출력
    unordered_map<string, string> huffmanCode;
    encode(root, EMPTY_STRING, huffmanCode);
 
    for (auto pair: huffmanCode) {
        cout << pair.first << " " << pair.second << endl;
    }
}
 
// 프로그램이 실행되는 main 함수
int main()
{
    // Ex 1의 텍스트 생성
    string str1 = "";
    for (int i=0; i<15; i++) {
        str1.append("A ");
    }
    for (int i=0; i<12; i++) {
        str1.append("B ");
    }
    for (int i=0; i<9; i++) {
        str1.append("C ");
    }
    for (int i=0; i<5; i++) {
        str1.append("D ");
    }
    for (int i=0; i<10; i++) {
        str1.append("E ");
    }
    for (int i=0; i<11; i++) {
        str1.append("F ");
    }
    for (int i=0; i<27; i++) {
        str1.append("r ");
    }

    // Ex 2의 텍스트 생성
    string str2 = "";
    for (int i=0; i<12; i++) {
        str2.append("ABC ");
    }
    for (int i=0; i<7; i++) {
        str2.append("ABCC ");
    }
    for (int i=0; i<19; i++) {
        str2.append("AB ");
    }
    for (int i=0; i<35; i++) {
        str2.append("A ");
    }
    for (int i=0; i<40; i++) {
        str2.append("B ");
    }
    for (int i=0; i<15; i++) {
        str2.append("BABA ");
    }
    for (int i=0; i<27; i++) {
        str2.append("ROOT ");
    }

    // 인코딩 결과 제시
    buildHuffmanTree(str1);
    cout << '\n';
    buildHuffmanTree(str2);
 
    return 0;
}
