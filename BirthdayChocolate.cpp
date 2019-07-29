#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the birthday function below.
int birthday(vector<int> s, int d, int m) {

//  1st Solution
// int ways = 0;
//     for(auto it = s.cbegin(); it != s.cend(); ++it){
//         if(d == std::accumulate(it, it + m, 0))
//             ways++;
//     }
//     return ways;

//  2nd solution
// int size ;
    
//     cin>>size;
//     vector<int> ivec(size);
//     for(int i =0; i <size; ++i)
//     {
//         cin>>ivec[i];
//     }
//     cin>>d>>m;
    
//     int temp = 0;
//     int count = 0;
    
//     if(size == 1)
//     {
//         temp = ivec[0];
//         if(temp!=d)
//         {
//             cout<<0<<endl;
//         }
//         else
//         {
//             cout<<1<<endl;
//         }
//     }
//     else
//     {
//         for(int i =0; i < (size-m)+1; ++i)
//         {
//             temp = ivec[i];
//             for(int j = i+1; j < i + m; ++j)
//             {
//                 temp+=ivec[j];
//             }
            
//             if(temp == d)
//             {
//                 count++;
//             }
//         }
        
//     }
// return count;

//  3rd Solution
// Half Learned from Discussions
int sum =0 ;
int count=0;

for(int i=0;i<s.size()-m+1;i++){
sum = 0;
for(int j = 0;j<m;j++){
    sum = sum + s[i+j];
}

if(sum==d){
count++;
}
}
return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    string dm_temp;
    getline(cin, dm_temp);

    vector<string> dm = split(rtrim(dm_temp));

    int d = stoi(dm[0]);

    int m = stoi(dm[1]);

    int result = birthday(s, d, m);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
