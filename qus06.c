//��Ŀ����
//�����������ͬ�෨���� n �����������������������������Լ���������ӵ������뺬�壻
//����ͬ�෨��һ�������α��������������㷨���£�
//a���� X(0)��Ϊ����������ӣ�
//b�����ݵ��ƹ�ʽ X(n+1) = (a*X(n)+b) mod M�����β���һ����������� X(1),X(2)����
//����Ϊ�����⣬������ݺ��������Ĳ�������ɱ��⡣
//���У�M �������ǲ��� 0 �� M-1 ֮���α���������� M �Ĵ�Сֱ��Ӱ��α��������е����ڳ��̣��� M ������ȡ�Ƚϴ��ֵ��
//a �� b ��ֵԽ�󣬲�����α�����ҲԽ����
//��� a �� M ������ʣ����������Ч�����á�
//���磺a.b �ɶ���Ϊ int �ͣ�
//���� X �ɶ���Ϊ int �ͣ���Ҫ��ֹ a,b ȡֵ̫����� X[i]�����
//M ��ȡ����������ֵ RAND_MAX(0x7FF)��
//���� X(0)������ȡ 1,2,3,��,��ȡ��ǰʱ����Ϊ���ӣ����������ɵ��������
//�����ʽ
//��һ��Ϊ 5 ���������ֱ�Ϊ�������������� N����������� seed�����ƹ�ʽ�� a,b,M;
//�����ʽ
//����� N ��,Ϊ������ n ����������Կո�ָ���
#include<stdio.h>
int main()
{
    int X[1000];
    int N=0,a=0,b=0,M=0;
    scanf("%d",&N);
    scanf("%d",&X[0]);
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&M);
    for(int i=1;i<N+1;i++)
    {
        X[i]=(a*X[i-1]+b)%M;
    }
    for(int i=1;i<N+1;i++)
    {
        printf("%d ",X[i]);
    }

}