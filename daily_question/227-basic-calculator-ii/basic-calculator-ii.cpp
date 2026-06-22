class Solution {
public:
    int prec(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    string postfix(string s) {
        string res;
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (c == ' ') continue;

            if (isdigit(c)) {
                while (i < s.size() && isdigit(s[i])) {
                    res += s[i];
                    i++;
                }
                res += ' ';
                i--;
            }
            else if (c == '(') {
                st.push(c);
            }
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    res += st.top();
                    res += ' ';
                    st.pop();
                }
                st.pop();
            }
            else {
                while (!st.empty() &&
                       st.top() != '(' &&
                       prec(st.top()) >= prec(c)) {
                    res += st.top();
                    res += ' ';
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.empty()) {
            res += st.top();
            res += ' ';
            st.pop();
        }

        return res;
    }

    int evaluate(string s) {
        stack<int> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') continue;

            if (isdigit(s[i])) {
                int num = 0;

                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                st.push(num);
                i--;
            }
            else {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                if (s[i] == '+') st.push(a + b);
                else if (s[i] == '-') st.push(a - b);
                else if (s[i] == '*') st.push(a * b);
                else if (s[i] == '/') st.push(a / b);
            }
        }

        return st.top();
    }

    int calculate(string s) {
        string post = postfix(s);
        return evaluate(post);
    }
};