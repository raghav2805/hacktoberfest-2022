#include <bits/stdc++.h>

using namespace std;

class StudentInfo
{
public:
    string name;
    string father_name;
    string dob;
    string branch;
    int rollno;
    int yoa;

    StudentInfo(string na, string father, string db, string bran, int roll, int ya)
    {
        name = na;
        father_name = father;
        dob = db;
        branch = bran;
        rollno = roll;
        yoa = ya;
    };
};

bool cmp(string a, string b)
{

    string str1 = a.substr(6, 4);
    string str2 = b.substr(6, 4);
    if (str1.compare(str2) != 0)
    {
        if (str1.compare(str2) < 0)
            return true;
        return false;
    }

    string month_a = a.substr(3, 2);
    string month_b = b.substr(3, 2);

    if (month_a != month_b)
    {
        return month_a < month_b;
    }

    string day_a = a.substr(0, 2);
    string day_b = b.substr(0, 2);
    if (day_a.compare(day_b) < 0)
        return true;
    return false;
}

class StudentRecord
{
public:
    vector<StudentInfo> sarr = {};

    void add(StudentInfo stu)
    {
        sarr.push_back(stu);
    }

    void sortbook()
    {
        sort(sarr.begin(), sarr.end(), cmp);
    }

    void show()
    {
        int n = (int)sarr.size();
        for (int i = 0; i < n; i++)
        {
            StudentInfo t = sarr[i];
            cout << t.name << endl;

            cout << t.rollno;

            t.name[0] = toupper(t.name[0]);

            cout.width(6);

            cout << left << t.name << endl;

            cout.width(6);

            cout << right << t.father_name << endl;

            cout << t.dob << endl;

            cout << endl
                 << endl;
        }
    }
};

int main()
{
    StudentInfo s1 = StudentInfo("Akash", "temp", "14/12/2001", "CSE", 100, 2009);
    StudentInfo s2 = StudentInfo("Tom", "temp2", "06/02/2002", "ECE", 130, 2007);
    StudentInfo s3 = StudentInfo("Mohan", "Rohan", "12/08/2002", "ECE", 456, 2006);

    StudentRecord sr = StudentRecord();

    sr.add(s1);
    sr.add(s2);
    sr.add(s3);
    sr.sortbook();
    sr.show();

    return 0;
}
