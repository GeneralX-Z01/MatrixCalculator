#include <iostream>
using namespace std;
int main()
{
    while (true)
    {
        string islem;
        cout << "kac matris uzerinde islem yapacaksiniz ? (tek / cok) : " << endl;
        cin >> islem;
        if (islem == "tek")
        {
            int a[50][50], transpose[50][50], row, column, i, j;

            cout << "matrisin boyutlarini giriniz: " << endl;
            cin >> row;
            cout << endl;
            cin >> column;

            cout << "matrisin elemanlarini giriniz: " << endl;

            // matris elemanlarini kullanicidan alma
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < column; ++j) {
                    cout << "giriniz a" << i + 1 << j + 1 << ": ";
                    cin >> a[i][j];
                }
            }

            // matrisin basilmasi
            cout << "girilen matris:  " << endl;
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < column; ++j) {
                    cout << " " << a[i][j];
                    if (j == column - 1)
                        cout << endl << endl;
                }
            }
            string islem2;
            cout << "girilen matris uzerinde hangi islemi yapmak istersiniz? (transpose,determinant,ters): ";
            cin >> islem2;
            //transpoze islemleri
            if (islem2 == "transpose")
            {
                // transpozenin hesaplanmasi
                for (int i = 0; i < row; ++i)
                    for (int j = 0; j < column; ++j) {
                        transpose[j][i] = a[i][j];
                    }

                // transpozenin basilmasi
                cout << "Matrisin transpozesi: " << endl;
                for (int i = 0; i < column; ++i)
                    for (int j = 0; j < row; ++j) {
                        cout << " " << transpose[i][j];
                        if (j == row - 1)
                            cout << endl << endl;
                    }

            }
            else if (islem2 == "ters")
            {
                float determinant = 0;
                //finding determinant
                for (i = 0; i < 3; i++)
                    determinant = determinant + (a[0][i] * (a[1][(i + 1) % 3] * a[2][(i + 2) % 3] - a[1][(i + 2) % 3] * a[2][(i + 1) % 3]));

                cout << "Matrisin tersi: " << endl;
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++)
                        cout << ((a[(j + 1) % 3][(i + 1) % 3] * a[(j + 2) % 3][(i + 2) % 3]) - (a[(j + 1) % 3][(i + 2) % 3] * a[(j + 2) % 3][(i + 1) % 3])) / determinant << "\t";

                    cout << "\n";
                }
            }
            else if (islem2 == "determinant")
            {
                float determinant = 0;
                //determinanti bulalim
                for (i = 0; i < 3; i++)
                    determinant = determinant + (a[0][i] * (a[1][(i + 1) % 3] * a[2][(i + 2) % 3] - a[1][(i + 2) % 3] * a[2][(i + 1) % 3]));
                cout << determinant;
            }
            else
            {
                cout << islem2 << " islemi yapamilmiyor. Tekrar deneyin" << endl;
            }
        }
        else if (islem == "cok")
        {
            string islem3;
            cout << "cok matrisler uzerinde hangi islemleri yapmak istersiniz?(topla, carp,cikar): ";
            cin >> islem3;
            if (islem3 == "topla")
            {
                while (true)
                {
                    int rowOne, colOne, rowTwo, colTwo, i, j;
                    int mat1[50][50], mat2[50][50], sum = 0;
                    cout << "birinci matrisin satir ve sutunu: ";
                    cin >> rowOne >> colOne;
                    cout << "ikinci matrisin satir ve sutunu: ";
                    cin >> rowTwo >> colTwo;
                    if (rowOne == rowTwo && colOne == colTwo)
                    {
                        cout << rowOne << "*" << colOne << " birinci matris elemanlarini giriniz: " << endl;
                        for (i = 0; i < rowOne; i++)
                        {
                            for (j = 0; j < colOne; j++)
                                cin >> mat1[i][j];
                        }
                        cout << rowOne << "*" << colOne << " ikinci matris elemanlarini giriniz: " << endl;
                        for (i = 0; i < rowOne; i++)
                        {
                            for (j = 0; j < colOne; j++)
                                cin >> mat2[i][j];
                        }
                        cout << "iki matrisin toplami:" << endl;
                        for (i = 0; i < rowOne; i++)
                        {
                            for (j = 0; j < colOne; j++)
                            {
                                sum = mat1[i][j] + mat2[i][j];
                                cout << sum << "  ";
                            }
                            cout << endl;
                        }
                        break;
                    }
                    else
                        cout << "\nBoyut hatali. Tekrar deneyin\n";
                }
            }
            else if (islem3 == "carp")
            {
                int a[50][50], b[50][50], mul[50][50], r, c, i, j, k;
                cout << "satir sayi =";
                cin >> r;
                cout << "sutun sayi=";
                cin >> c;
                cout << "birinci matris elemanlari=" << endl;
                for (i = 0; i < r; i++)
                {
                    for (j = 0; j < c; j++)
                    {
                        cin >> a[i][j];
                    }
                }
                cout << "ikinci matris elemanlari\n";
                for (i = 0; i < r; i++)
                {
                    for (j = 0; j < c; j++)
                    {
                        cin >> b[i][j];
                    }
                }
                cout << "carpim sonucu:\n";
                for (i = 0; i < r; i++)
                {
                    for (j = 0; j < c; j++)
                    {
                        mul[i][j] = 0;
                        for (k = 0; k < c; k++)
                        {
                            mul[i][j] += a[i][k] * b[k][j];
                        }
                    }
                }
                //sonucu yazdirir   
                for (i = 0; i < r; i++)
                {
                    for (j = 0; j < c; j++)
                    {
                        cout << mul[i][j] << " ";
                    }
                    cout << "\n";
                }
            }
            else if (islem3 == "cikar")
            {
                while (true)
                {
                    int rowOne, colOne, rowTwo, colTwo, i, j;
                    int matOne[50][50], matTwo[50][50], matSub[50][50];
                    cout << "birinci matrisin satir ve sututn sayini giriniz: ";
                    cin >> rowOne >> colOne;
                    cout << "ikinci matrisin satir ve sutun sayini giriniz: ";
                    cin >> rowTwo >> colTwo;
                    if (rowOne == rowTwo && colOne == colTwo)
                    {
                        cout << rowOne * colOne << " birrinci matris elemanlari: ";
                        for (i = 0; i < rowOne; i++)
                        {
                            for (j = 0; j < colOne; j++)
                                cin >> matOne[i][j];
                        }
                        cout << rowTwo * colTwo << " ikinci matris elemanlari: ";
                        for (i = 0; i < rowTwo; i++)
                        {
                            for (j = 0; j < colTwo; j++)
                                cin >> matTwo[i][j];
                        }
                        cout << "\nmatris cikartma sonucu:\n";
                        for (i = 0; i < rowOne; i++)
                        {
                            for (j = 0; j < colOne; j++)
                            {
                                matSub[i][j] = matOne[i][j] - matTwo[i][j];
                                cout << matSub[i][j] << "  ";
                            }
                            cout << endl;
                        }
                        break;
                    }
                    else
                        cout << "\n boyut hatasi. tekrar deneyin" << endl;
                }
            }
        }
        string devam;
        cout << "devam?(e/h)";
        cin >> devam;
        if (devam == "h")
        {
            break;
        }
    }
}
