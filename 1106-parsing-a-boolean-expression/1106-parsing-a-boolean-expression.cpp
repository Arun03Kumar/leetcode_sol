class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> op;
        stack<char> bool_val;

        for(char ch: expression) {
            if(ch == '&' || ch == '|' || ch == '!') op.push(ch);
            else {
                if(ch == ')') {
                    char top_on_op = op.top();
                    op.pop();

                    bool temp = bool_val.top() == 't' ? true : false;
                    while(!bool_val.empty() && bool_val.top() != '(') {
                        if(top_on_op == '&') {
                            temp &= (bool_val.top() == 'f' ? false : true);
                        }
                        else if(top_on_op == '|') {
                           temp |= (bool_val.top() == 'f' ? false : true); 
                        }
                        else {
                          temp = (bool_val.top() == 'f' ? true : false);
                          bool_val.pop();
                          break;
                        }

                        bool_val.pop();
                    }
                    bool_val.pop();
                    if(temp == true) bool_val.push('t');
                    else bool_val.push('f');
                }
                else if(ch == ',') {
                    continue;
                }
                else {
                    bool_val.push(ch);
                }
            }
        }

        cout << bool_val.top();
        return bool_val.top() == 'f' ? false : true;
    }
};