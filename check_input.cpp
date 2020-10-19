#include <check_input.h>
using namespace std;

string ITC::check_input(vector<string> a, string name_element){

    cout << name_element << "(";
    for (size_t i = 0; i < a.size(); i++) {
        cout << a[i];
        if(i+1 < a.size()) cout << "/";
    }
    cout << ")\n";
    //перечисляем подходящие значения


    string temp;                      //ввод пользователя
    bool idiot = true;                //по умолчанию пользователь идиот
    cin >> temp;

    for (size_t i = 0; i < a.size() && idiot; i++){
        if (temp == a[i]) idiot = false; //если ответ пользователя совпадает с желаемым, он не идиот
    }

    if(idiot){
        cout << "ERROR: wrong value!\n";
        return ITC::check_input(a, name_element); //если пользователь все же идиот, просим его ввести еще раз
    } else {
        return temp; //верни значение пользователя
    }
}

double ITC::check_input(string name_element){
    double input;
    bool valid= false;
    do
    {
        cout << "Enter a number of " << name_element << endl;
        cin >> input;
        if (cin.good()){
            valid = true;
        }
        else{

            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "ERROR: wrong value! Please re-enter." << endl;
        }
    } while (!valid);

    return input;

}

int ITC::check_input_int(string name_element){
    int input;
    bool valid = false;
    do {
        cout << "Enter a number of " << name_element << endl;
        cin >> input;
        if (cin.good()){
            valid = true;
        }
        else{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "ERROR: wrong value! Please re-enter." << endl;
        }
    } while (!valid);

    return input;
}

bool ITC::check_ans(std::string q){
    return "y"==ITC::check_input({"y","n"}, q);
}

int ITC::menu(){
    vector<string> q = {"1-add pipe","2-add station","3-see all","4-edit pipe","5-edit station","6-save","7-load","0-exit"};
    cout << "options: ";
    for (auto t: q){
        if(t != q.back()) cout << t << ", ";
        else              cout << t << endl;
    }
    return check_input_int("choose option");
}
