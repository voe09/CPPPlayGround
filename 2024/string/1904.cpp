class Solution {
public:
    int numberOfRounds(string loginTime, string logoutTime) {
        int login = datestrToMins(loginTime);
        int logout = datestrToMins(logoutTime);
        if (logout < login) logout += 24 * 60;
        int loginBucket = login % 15 == 0 ? login/15 - 1 : login/15;
        int logoutBucket = logout / 15;
        return max(0, logoutBucket - loginBucket - 1); 
    }

private:
    int datestrToMins(string &datestr) {
        int mins = 0;
        istringstream is(datestr);
        string token;
        getline(is, token, ':'); // hours
        mins = stoi(token) * 60;
        getline(is, token, ':'); // mins
        mins += stoi(token);
        return mins;
    }
};