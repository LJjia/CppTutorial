/**
 * @Author: Jialiangjun
 * @Description: 描述strings类
 * @Date: Created on 11:35 2021-08-19.
 * @Modify:
 */


#include <string>
#include <iostream>
#include <cstring>

void TestStrings(){
    using namespace std;
    //string 拥有和数组内类似的使用方法
    std::string str1;
    char charr[20];
    //初始化方法
    std::string str2=" hello world ";
    char first_data[]={"fitst data"};
    char second_data[]{"second data"};
    string third_data={"third data"};
    string fourth_data {"fourth data"};
    string normal_str {"1234"};
    string uninit_data;
    // 可以和python字符串一样,还可以拼接
    uninit_data=fourth_data;
    string merge_data=third_data+fourth_data+" merge end :";
    cout<<"pt Init strings "<<first_data<<second_data<<third_data<<fourth_data<<endl;
    cout<<"pt merge strings "<<merge_data<<"----"<<uninit_data<<normal_str.size()<<endl;

    // cstring 提供了类似的函数功能来完成对应的c语言函数
    // 但是这些c字串只能处理对应的char类型,string类型有自己独特的一套函数
    char charr1[40];
    char charr2[40]="library";
    strcpy(charr1,charr2);
    strcat(charr1," ok,fine");
    cout<<" disp charr1 "<<strlen(charr1)<<" contant:"<<charr1<<endl;

    // c的数组来说,char input_char[20] {0}; 和char input_char[20] {};都是进行初始化
    // 但是对于string类型来说,初始化应该有所区别
    char input_char[20] {0};
    // 应该使用string input_str {};来表示初始化string对象 而不是// 应该使用string input_str {0};
    // {0}的这种写法会将input_str对象初始化为长度为1,含有"\0"字符的对象(将会输出乱码),
    string input_str {};
    cout<<"size char "<<strlen(input_char)<<" strings "<<input_str.size()<<input_str[0]<<endl;
    // char 字符串和string类型获取输入的函数有区别
    cin.getline(input_char,20);
    getline(cin,input_str);
    cout<< "after cin "<<input_char<<" "<<input_str<<endl;
    cout<<"size char "<<strlen(input_char)<<" strings "<<input_str.size()<<endl;

    //各种字符串值 对各种字符串赋值时必须增加L u U等这些字符串类型
    wchar_t wcharr[]=L"1234"; //size 20 类似char32
    char16_t char16r[]=u"1234"; //size 10
    char32_t char32r[]=U"1234"; //size 20
    // 原始字符串中不会啊生转义 用R"()"来特定标志 当然也可以用自定义EOF符号,比如 R"*(...)*"来表示,但空格不可以当作自定义符号
    char orichar[]=R"(1234\n)"; //size 7
    // utf-8编码
    char utf8_enc_char[]=u8"1234"; //size 5
    cout<<"type of string size "<< " "<<sizeof(wcharr)<<" "<< sizeof(char16r)<<" "
    << sizeof(char32r)<<" "<< sizeof(orichar)<<" " << sizeof(utf8_enc_char)<<endl;




//goto END;

    std::cout<<str2;
    cout<<"input to str1";
    cin>>str1;
    cout << "input to charr";
    cin>> charr;
    cout<<"charr "<< charr<<" str1 "<<str1<<endl;
    cout<<"third idx "<<charr[3]<<" "<<str1[3];
END:
    return ;
}
