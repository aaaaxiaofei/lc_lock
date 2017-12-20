// This is the text editor interface. 
// Anything you type or change here will be seen by the other person in real time.

/*
class Packetizer
void packetize(string input)

%--> start of a packet
$--> end of a packet

1. abc%defg$hi --> print out "defg"
2. abc%def
3. ghijk
4. lmn$op --> print out "defghijklmn"
5. abc%def$ghk%jkl$mn --> print out "def", "jkl"
6. dfasd$kdsfj%dkf --> invalid input




*/


class Packetizer {
private: 
    stack<string> s;
    bool flag_record;
    
public:    

    Packetizer() {
        s = "";
    }
    void packetize(string input) {
        
        // go through the input
        // if meet a '%', set flag_record as true;
        // if  meet a '$', set flag_record as false;
        // if  flag_record is true, add chars to s
        // if flag_record is false, not recording
        // if the char is '$', print the current s, set s = ""


1. abc%def%
2. ghi%jk$lmn$o --> print "jk", "ghilmn"
3. p%qrs$tuv$ab --> print "qrs", "defoptuv"


//print : "jk" "ghilmn"  "qrs" "defoptuv"
        
       
        
        for (auto c : input) {
            if (c == '%') {
                s.push("");
            }
            else if (c == '$') {
                cout << s.top() << endl;
                s.pop();
            }
            if (!s.empty() && c != '%') s.top() + c;
        }
        
    }
    
};
