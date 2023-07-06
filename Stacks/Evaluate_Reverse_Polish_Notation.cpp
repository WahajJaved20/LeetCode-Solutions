class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        for(int i=0;i<n;i++){
            int num1,num2;
            if(!isdigit(tokens[i][0]) && tokens[i].length()==1){
                num1 = st.top();
                st.pop();
                num2 = st.top();
                st.pop();
            }
            if(tokens[i] == "+"){
                st.push(num1 + num2);
            }else if(tokens[i] == "-"){
                st.push(num2-num1);
            }else if(tokens[i] == "*"){
                cout<<num1 <<" "<<num2<<endl;
                st.push(num1 * num2);
            }else if (tokens[i] == "/"){
                st.push(num2 / num1);
            }else{
                int num = stoi(tokens[i]);
                st.push(num);
            }
        }
        return st.top();
    }
};
