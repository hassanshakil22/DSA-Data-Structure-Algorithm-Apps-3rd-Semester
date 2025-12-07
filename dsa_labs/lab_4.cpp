#include <iostream>
#include <string>
using namespace std;

//--------------------------------QUESTION NO.01
class Stack {
    char *arr;
    int capacity;
    int topin;
public:
    Stack(int size =100) {
        capacity =size;
        arr = new char[capacity];
        topin = -1;
    }

    void push(char x) {
        if (topin+1== capacity) {
            int newcap= capacity * 2;
            char *newarr=new char[newcap];
            for (int i =0;i<=topin; i++)
                newarr[i]=arr[i];
            delete[] arr;
            arr = newarr;
            capacity =newcap;
        }
        arr[++topin]=x;
    }

    void pop() {
        if (topin>=0)
            topin--;
    }
    char top() {
        if (empty()) {
            cout<<"stack is empty" << endl;
            return ' ';
        }
        return arr[topin];
    }
    bool empty() {
        return topin == -1;
    }

    ~Stack() {
        delete[] arr;
    }
};
bool checkpalindrome(const string &s) {
    Stack st((int)s.length());
    for (int i=0;i<(int)s.length();i++) {
        char c=s[i];
        st.push(c);
    }
    for (int i=0;i<(int)s.length();i++) {
        char c = s[i];
        if (c != st.top())
            return false;
        st.pop();
    }
    return true;
}

//--------------------------------  QUESTION NO.02
string buildstring(const string &s){
    Stack st((int)s.length());
    for (int i=0;i<(int)s.length();i++) {
        char c=s[i];
        if (c=='#') {
            if(!st.empty()) {
              st.pop();
            }
        } else{st.push(c);
        }
    }
    string res= "";
    while (!st.empty()){
        char topChar=st.top();
        res = topChar+ res;
        st.pop();
    }
    return res;
}
bool backspacecompare(const string &s, const string &t) {
    string firstb = buildstring(s);
    string secondb = buildstring(t);
    if (firstb == secondb) {
        return true;
    } else {
        return false;
    }
}
////-------------------------------- QUESTION NO.03
void permute(int *arr, int start, int n){
    if (start==n) {
        cout<<"[";
        for (int i = 0; i < n; i++) {
            cout << arr[i];
            if (i != n - 1) cout << ",";
        }
        cout<<"]"<<endl;
        return;
    }
    for (int i=start; i < n; i++) {
        int temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        permute(arr, start + 1, n);

        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
    }
}
////-------------------------------- QUESTION NO.04
class boardsearch{
	private:
    char **board;
    int rows, cols;
    bool dfs(int r, int c, const string &word, int index) {
        if (index == (int)word.length())
            return true;
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            return false;
        if (board[r][c] != word[index])
            return false;
        char temp = board[r][c];
        board[r][c]='#';
        bool found =
            dfs(r+1, c,word,index+1) ||
            dfs(r-1,c, word,index+1) ||
            dfs(r,c+1, word,index+1) ||
            dfs(r,c-1, word,index+ 1);
        board[r][c] = temp;
        return found;
    }
public:
    boardsearch(char **b, int r, int c) {
        rows = r;
        cols = c;
        board = new char *[rows];
        for (int i = 0; i < rows; i++) {
            board[i] = new char[cols];
            for (int j = 0; j < cols; j++) {
                board[i][j] = b[i][j];
            }
        }
    }
    bool exist(const string &word) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(i, j, word, 0))
                    return true;
            }
        }
        return false;
    }

    ~boardsearch() {
        for (int i = 0; i < rows; i++)
            delete[] board[i];
        delete[] board;
    }
};

int main() {
    //QUESTION NO.01
    // string str;
    // cout << "enter palindrome: ";
    // cin >> str;
    // bool result = checkpalindrome(str);
    // if (result == true) {
    //     cout << "palindrome" << endl;
    // } else {
    //     cout << "not palindrome" << endl;
    // }

    //QUESTION NO.02
    string firstst;
    string secondst;
    cout << "enter first string for backspace compare: ";
    cin >> firstst;
    cout << "enter second string: ";
    cin >> secondst;
    bool result = backspacecompare(firstst, secondst);
    if (result == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    //QUESTION NO.03
    int n;
    cout << "enter no. of elements for permutation: ";
    cin >> n;
    int *nums = new int[n];
    cout << "enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "permutations:" << endl;
    permute(nums, 0, n);
    delete[] nums;

    //QUESTINO NO.04
    int rows = 3;
    int cols = 4;
    char **b1 = new char *[rows];
    for (int i = 0; i < rows; i++)
        b1[i] = new char[cols];
    b1[0][0] = 'A'; b1[0][1] = 'B'; b1[0][2] = 'C'; b1[0][3] = 'E';
    b1[1][0] = 'S'; b1[1][1] = 'F'; b1[1][2] = 'C'; b1[1][3] = 'S';
    b1[2][0] = 'A'; b1[2][1] = 'D'; b1[2][2] = 'E'; b1[2][3] = 'E';
    boardsearch bs1(b1, rows, cols);
    string word1 = "ABCCED";
    cout << (bs1.exist(word1) ? "true" : "false") << endl;
    string word2 = "ABCB";
    cout << (bs1.exist(word2) ? "true" : "false") << endl;
    for (int i = 0; i < rows; i++)
        delete[] b1[i];
    delete[] b1;


    return 0;

}
