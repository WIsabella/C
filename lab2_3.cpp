
#include<iostream>

using namespace std;

const float PI =3.1416;
int main()
{
    int iType;
    float radius,a,b,area;

    cout <<"闁搞儲鍎抽懜浼存儍閸曨叀顫﹂柛銊ヮ儎鐠愶拷?(1-闁革箑妫楅懜锟� 2-闂傗偓閹稿孩鐓欑憸甯嫹 3-婵繐绲鹃弻鐔汇亹閿燂拷):";
    cin >>iType;
    switch(iType)
    {
        case 1:
        cout<<"闁革箑妫涘▓鎴﹀础婵犲倻绐炲☉鎾跺皑缁憋拷";
        cin>>radius;
        area=PI*radius * radius;
        cout <<"闂傚牄鍨昏ⅶ濞戞搫鎷�:"<<area<<endl;
        break;

        case 2:
        cout <<"闁活厸鏅涢懜浼存儍閸曨垱姣愬☉鎿勬嫹: ";
        cin>>a;
        cout <<"闁活厸鏅涢懜浼存儍閸曨偒鍟嶅☉鎿勬嫹: ";
        cin >>b;
        area=a*b;
        cout <<"闂傚牄鍨昏ⅶ濞戞搫鎷�:"<<area<<endl;
        break;

        case 3:
        cout <<"婵繐绲鹃弻鐔汇亹閵忋垺鐣遍弶鍫濈秺閺嗚鲸绋夐敓锟�: ";
        cin>>a;
        area=a*a;
        cout <<"闂傚牄鍨昏ⅶ濞戞搫鎷�:"<<area<<endl;
        break;
        default:
        cout <<"濞戞挸绉靛Σ鎼佸触閸喓銆婇柣銊ュ缁额參宕楅妷銉㈠亾绾纾�"<<endl;
        
    }

}