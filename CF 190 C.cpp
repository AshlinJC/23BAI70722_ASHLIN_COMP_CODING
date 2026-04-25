#include <bits/stdc++.h>
using namespace std;

vector<string> tokens;
int idx = 0;

string build() {
    if (idx >= tokens.size()) return "";

    string t = tokens[idx++];
    
    if (t == "int") {
        return "int";
    } else { // pair
        string left = build();
        string right = build();
        
        if (left == "" || right == "") return "";
        
        return "pair<" + left + "," + right + ">";
    }
}

int main() {
    int n;
    cin >> n;
    
    tokens.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> tokens[i];
    }

    string ans = build();

    // check if all tokens used
    if (idx != n || ans == "") {
        cout << "Error occurred";
    } else {
        cout << ans;
    }
}
