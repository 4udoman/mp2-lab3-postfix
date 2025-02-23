#ifndef __OPERATIONS_H__
#define __OPERATIONS_H__

#include <map>

using namespace std;

class Operations // �����, �������� �������������� ��������
{
private:
    map<string, vector<int>> ops; // string - name of operation; vector<int> - priority, arity; ops - OPerationS
public:
    Operations() // ��� ���������� �������� � �����������, ����������� ����� ����������� ������ ���� �������� � Calc � �������� ������������ � static string str_op()
    {
        ops.emplace("sqrt", vector<int>{ 3, 1 });
        ops.emplace("sin", vector<int>{ 3, 1 });
        ops.emplace("cos", vector<int>{ 3, 1 });
        ops.emplace("*", vector<int>{ 2, 2 });
        ops.emplace("/", vector<int>{ 2, 2 });
        ops.emplace("+", vector<int>{ 1, 2 });
        ops.emplace("-", vector<int>{ 1, 2 });
        ops.emplace("(", vector<int>{ 0, 0 });
        ops.emplace(")", vector<int>{ 0, 0 });
    }

    static string str_op() { return string("sqrt(v), sin(v), cos(v), *, /, +, -, (, )"); }

    bool IsOperation(const string& elem) const { return ops.find(elem) != ops.end(); } // �������� �������� �� ������ ������� ���������, ������� ��������� � ������

    int GetPriority(const string& elem) { return ops[elem][0]; } // �������� ��������� � �������� ��������, �������� ������������� �� ������������� 
    
    int GetArity(const string& elem) { return ops[elem][1]; } // �������� ������� � �������� ��������, �������� ������������� �� ������������� 

    double Calc(const string& elem, double right, double left = 0) // ���������
    {
        if (elem == "sqrt")
            return sqrt(right);
        if (elem == "sin")
            return sin(right);
        if (elem == "cos")
            return cos(right);
        if (elem == "*")
            return right * left;
        if (elem == "/")
            return  right / left;
        if (elem == "+")
            return  right + left;
        if (elem == "-")
            return right - left;
    }
};

#endif
