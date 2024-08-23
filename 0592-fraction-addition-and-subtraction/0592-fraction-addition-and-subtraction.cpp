class Solution {
public:
    string fractionAddition(string expression) {
        // initially take numerator as 0 and denominator as 1, becuase we can't take denominator as 0, this would contain answer.
        // now parse the current numerator and denominator and solve them with numerator and denominator 
        // but first check if number can be negative if current character contains - sign then multiply numerator to -1;
        // if current char contains + or - then skip
        // at last find gcd of numerator and denominator and divide both of them.
        int numerator = 0;
        int denominator = 1;

        int n = expression.size();

        int i = 0;
        while(i < n) {

            int curr_nume = 0, curr_deno = 0;

            bool is_negative = (expression[i] == '-');

            if(expression[i] == '+' || expression[i] == '-') {
                i++;
            }

            while(i < n && isdigit(expression[i])) {
                int val = expression[i] - '0';
                curr_nume = (curr_nume * 10) + val;
                i++;
            }

            i++;

            if(is_negative) {
                curr_nume *= -1;
            }

            while(i < n && isdigit(expression[i])) {
                int val = expression[i] - '0';
                curr_deno = (curr_deno * 10) + val;
                i++;
            }

            numerator = numerator * curr_deno + denominator * curr_nume;
            denominator = denominator * curr_deno;
        }

        int GCD = abs(__gcd(numerator, denominator));

        numerator /= GCD;
        denominator /= GCD;

        return to_string(numerator) + '/' + to_string(denominator);
    }
};