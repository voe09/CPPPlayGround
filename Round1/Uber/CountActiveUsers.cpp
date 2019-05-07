/*
Given input which is vector of log entries of some online system
each entry is something like (user_name, login_time, logout_time),
come up with an algorithm with outputs number of users logged in the system
at each time slot in the input, output should contains only the time slot
which are in the input. For the example given below output should contain
timeslots [(1.2, 1), (3.1, 2), (4.5, 1), (6.7, 0), (8.9, 1), (10.3, 0)]
[
('Jane', 1.2, 4.5),
('Jin', 3.1, 6.7),
('June', 8.9, 10.3)
]
 */

Sort the input values based on time. Walk down this array one by one, noting the number of logins and logouts.

Storage is O(n) and runtime is O(nlogn), n = number of login/out values

class InputValue {
    String name;
    double login;
    double logout;
}

class Type implements Comparable {
    boolean loggedin;
    double time;

    int compareTo(Type that) {
        return this.time - that.time
    }
}

class ReturnValue {
    double time;
    int numLoggedIn;
}

public List<ReturnValue> findLoggedIn(List<InputValue> list) {
    List<Type> loggedIn = new ArrayList<Type>();
    List<ReturnValue> retValue = new ArrayList<ReturnValue>();
    int loggedInNow = 0

    for (InputValue iv: list) {
        loggedIn.add(iv.login, true);
        loggedIn.add(iv.logout, false);
    }

    Collections.sort(loggedIn);

    for(Type t: loggedIn) {
        if (t.loggedin == true)
            loggedInNow++;
        else loggedInNow--;

        retValue.add(t.time, loggedInNow);
    }

    return retValue;
}
