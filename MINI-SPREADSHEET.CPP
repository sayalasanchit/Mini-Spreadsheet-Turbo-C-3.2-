//                  ******************************************************************************************
//
//                                  Header files.
//
//                  ******************************************************************************************

#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>


//                  ******************************************************************************************
//
//                                  Class body.
//
//                  ******************************************************************************************

class file
{
	int r,c;
public:
    char a[5][5][5];
    char name[100];
	void Input();
	void Output();
	void Formula(int o1,int o2);
	char *getn()
	{
		return name;
	}
};file fileobj;


//                  ******************************************************************************************
//
//                                  Function for input.
//
//                  ******************************************************************************************

void file::Input()
{
	do
    {
    cout << "Enter the number of rows (upto 10)" << endl;
    cin >> r;
    cout << "Enter the number of columns (upto 6)" << endl;
    cin >> c;

    if (r>10||c>6)
	{cout << "Enter the number of Rows and Columns upto limit provided." << endl;
	getch();
	clrscr();
    }
    }
    while(!(r<=10&&c<=6&&r>0&&c>0));

    clrscr();

    cout << "Enter the main heading for the table" << endl;
    gets (name);

    for (int j=0;j<c;j++)
    {
	cout << "Enter heading for column " << j+1 << "- " ;
	gets (a[0][j]);
    }

    for (int i=1;i<r;i++)
    {
	for (int j=0;j<c;j++)
	{
	    cout << i << "." << j+1 << "- Enter " << a[0][j] << endl;
	    gets (a[i][j]);
	    if ((a[i][j][0]=='$')&&(a[i][j][1]=='$'))
	    Formula(i,j);
	}
	cout << "__________________________________________________________________" << endl;
    }
}


//                  ******************************************************************************************
//
//                                  Function for output.
//
//                  ******************************************************************************************

void file::Output()
{
    int s;
	    clrscr();
    cout << "                           **  " << name << "  **" << endl << endl;

	for ( int l=1;l<=c*12;l++)
    {
	cout << "-";
    }
    cout << endl;

    for (int i=0;i<r;i++)
    {
	for (int j=0;j<c;j++)
	{
	    cout << "| " << a[i][j];
	for ( s=1;s<=10-(strlen (a[i][j]));s++)
	    {
		cout << " ";
	    }
	}
	for ( s=1;s<=10-(strlen (a[i][j]));s++)
	    {
		cout << "\b|";
	    }
    cout << endl;
	    for (int l=1;l<=c*12;l++)
	{
	    cout << "-";
	}
	cout << endl;
    }
    getch();
    clrscr();
}


//                  ******************************************************************************************
//
//                                  Function to check and apply the formula.
//
//                  ******************************************************************************************

void file::Formula(int o1,int o2)
{
    float y=0,x=1;
    int inc=0;
//                  ******************************************************************************************
    if (a[o1][o2][2]=='a'&&a[o1][o2][3]=='d'&&a[o1][o2][4]=='d')
    {
    char d[10][3];
    int u=0;
    for (int v=0;a[o1][o2][v]!='\0';v++)
    if (isdigit(a[o1][o2][v]))
	 {
	     if ((a[o1][o2][v]-'0')>=o2)
	    {
	    d[u][0]=a[o1][o2][v];
	    d[u][1]='\0';
	    u++;
	    }
	    else
	    inc=1;
	 }
	 if (!(a[o1][o2][5]=='('&&a[o1][o2][v]==')'))
	inc=1;
     if (inc==0)
    {
	for (int q=0;q<u;q++)
	y+=atoi(a[o1][atoi(d[q])-1]);
	itoa(y,a[o1][o2],10);
        cout << "Added.\n";
    }
    }
//                  ******************************************************************************************
    else if (a[o1][o2][2]=='s'&&a[o1][o2][3]=='u'&&a[o1][o2][4]=='b')
    {
	y=atoi(a[o1][(a[o1][o2][8]-'0')-1])-atoi(a[o1][(a[o1][o2][6]-'0')-1]);
    itoa(y,a[o1][o2],10);
    cout << "Subtracted.\n";
    }
//                  ******************************************************************************************
    else if (a[o1][o2][2]=='m'&&a[o1][o2][3]=='u'&&a[o1][o2][4]=='l')
    {
    char d[10][3];
    int u=0;
    for (int v=0;a[o1][o2][v]!='\0';v++)
    if (isdigit(a[o1][o2][v]))
	 {
	     if ((a[o1][o2][v]-'0')>=o2)
	    {
            d[u][0]=a[o1][o2][v];
            d[u][1]='\0';
            u++;
	    }
	    else
            inc=1;
	 }
	 if (!(a[o1][o2][5]=='('&&a[o1][o2][v]==')'))
        inc=1;
     if (inc==0)
    {
        for (int q=0;q<u;q++)
        x*=atoi(a[o1][atoi(d[q])-1]);
        itoa(x,a[o1][o2],10);
        cout << "Multiplied.\n";
    }
    }
//                  ******************************************************************************************
    else if (a[o1][o2][2]=='d'&&a[o1][o2][3]=='i'&&a[o1][o2][4]=='v')
    {
	x=atoi(a[o1][(a[o1][o2][8]-'0')-1])/atoi(a[o1][(a[o1][o2][6]-'0')-1]);
    itoa(x,a[o1][o2],10);
    cout << "Divided.\n";
    }
//                  ******************************************************************************************
    else if (a[o1][o2][2]=='e'&&a[o1][o2][3]=='d'&&a[o1][o2][4]=='i'&&a[o1][o2][5]=='t')
    {
    if (isdigit(a[o1][o2][7]))
    {
    if (((a[o1][o2][7]-'0')-1)>=o1||(a[o1][o2][9]-'0')<=o2||a[o1][o2][6]!='('||a[o1][o2][8]!=','||a[o1][o2][10]!=')')
        inc=1;
    cout << "Enter the value for row#" << a[o1][o2][7] << " column#" << a[o1][o2][9] << endl;
    gets(a[(a[o1][o2][7]-'0')-1][a[o1][o2][9]-'0']);
    }
    else if (a[o1][o2][7]=='h')
    {
    cout << "Enter the value for heading#" << a[o1][o2][8] << endl;
    gets(a[0][a[o1][o2][8]-'0']);
    if ((a[o1][o2][9]-'0')<=o2||a[o1][o2][6]!='('||a[o1][o2][9]!=')')
        inc=1;
    }
    else
    inc=1;
    }
//                  ******************************************************************************************
    else if (a[o1][o2][2]=='a'&&a[o1][o2][3]=='v'&&a[o1][o2][4]=='g')
    {
    char d[10][3];
    int u=0;
    for (int v=0;a[o1][o2][v]!='\0';v++)
    if (isdigit(a[o1][o2][v]))
	 {
	     if ((a[o1][o2][v]-'0')>=o2)
	    {
            d[u][0]=a[o1][o2][v];
            d[u][1]='\0';
            u++;
	    }
	    else
            inc=1;
	 }
	 if (!(a[o1][o2][5]=='('&&a[o1][o2][v]==')'))
        inc=1;
     if (inc==0)
    {
        for (int q=0;q<u;q++)
        y+=atoi(a[o1][atoi(d[q])-1]);
        y=y/u;
        itoa(y,a[o1][o2],10);
        cout << "Average calculated.\n";
    }
    }
//                  ******************************************************************************************
    else if (a[o1][o2][2]=='v'&&a[o1][o2][3]=='i'&&a[o1][o2][4]=='e'&&a[o1][o2][5]=='w')
    {
        for (int v=0;v<10;v++)
            a[o1][o2][v]=' ';
        Output();
        cout << o1 << "." << o2+1 << "- Enter " << a[0][o2] << endl;
	    gets (a[o1][o2]);
        getch();
    }
//                  ******************************************************************************************
    else if (a[o1][o2][2]=='c'&&a[o1][o2][3]=='p'&&a[o1][o2][4]=='y')
    {
        if (!(a[o1][o2][5]=='('&&a[o1][o2][7]==')'))
            inc=1;
        else
	    strcpy(a[o1][o2],a[o1][(a[o1][o2][6]-'0')]);
    }
//                  ******************************************************************************************
     else if (a[o1][o2][2]=='s'&&a[o1][o2][3]=='e'&&a[o1][o2][4]=='e')
    {
        for (int v=0;v<10;v++)
            a[o1][o2][v]=' ';
        clrscr();
        cout << "Formulas that can be used:\n";
        cout << "1.ADDITION\n$$add(1,2,3,....):-Sum of columns 1,2,3,....\n";
        cout << "2.SUBTRACTION\n$$sub(1,2):-Difference of columns 2 and 1 i.e.(col_2-col_1)\n";
        cout << "3.MULTIPLICATION\n$$mul(1,2,3,....):-Product of columns 1,2,3,....\n";
        cout << "4.DIVISION\n$$div(1,2):-Division of columns 2 and 1 i.e.(col_2/col_1)\n";
        cout << "5.AVERAGE\n$$avg(1,2,3,....):-Average of columns 1,2,3,....\n";
        cout << "6.EDIT PREVIOUSLY ENTERED DATA\n$$edit(1,2):-Edit the data of cell with row#1 and column#2.\n$$edit(h1):-Edit the data of heading#1.\n";
        cout << "7.VIEW THE TABLE\n$$view:-View the table.\n";
        cout << "8.COPY THE DATA\n$$cpy(1):-Copy the data from column#1.\n";
        cout << "\t\tNOTE :All the calculations are for integer type.";
        getch();
        clrscr();
        cout << o1 << "." << o2+1 << "- Enter " << a[0][o2] << endl;
	    gets (a[o1][o2]);
    }
//                  ******************************************************************************************
    else
    {
        for (int v=0;v<10;v++)
            a[o1][o2][v]=' ';
        clrscr();
        cout << "No such Formula Found.";
        getch();
        clrscr();
        cout << o1 << "." << o2+1 << "- Enter " << a[0][o2] << endl;
	    gets (a[o1][o2]);
    }

    if (inc==1)
    {
        for (int v=0;v<10;v++)
            a[o1][o2][v]=' ';
        clrscr();
        cout << "Formula entered has wrong syntax.\nUse $$see to see all the formulas.\n";
        getch();
        clrscr();
        cout << o1 << "." << o2+1 << "- Enter " << a[0][o2] << endl;
	    gets (a[o1][o2]);
    }
}


//                  ******************************************************************************************
//
//                                  Other functions.
//
//                  ******************************************************************************************

void Create();
void Menu();
void Open();
void Edit(int saved,char nm[]);
void Delete();
void Help();


fstream fil;


//                  ******************************************************************************************
//
//                                  Main body of the program.
//
//                  ******************************************************************************************

void main()
{
    clrscr();
    cout << " _______________________________________________________________________ " << endl;
    cout << " |                                                                     | " << endl;
    cout << " | #   #  #####  #   #  #####   000000000000000000000000000000000000   | " << endl;
    cout << " | ## ##    #    ##  #    #    00-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+00  | " << endl;
    cout << " | # # #    #    # # #    #   00-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+00 | " << endl;
    cout << " | #   #    #    #  ##    #    00-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+00  | " << endl;
    cout << " | #   #  #####  #   #  #####   000000000000000000000000000000000000   | " << endl;
    cout << " |                                                                     | " << endl;
    cout << " |    O      **** **** **** ****  **  **   **** *  * **** **** *****   | " << endl;
    cout << " |  O   O    *    *  * *  * *    *  * * *  *    *  * *    *      *     | " << endl;
    cout << " |O   O   O  **** **** **** ***  **** *  * **** **** ***  ***    *     | " << endl;
    cout << " |  O   O       * *    **   *    *  * * *     * *  * *    *      *     | " << endl;
    cout << " |    O      **** *    * ** **** *  * **   **** *  * **** ****   *     | " << endl;
    cout << " _______________________________________________________________________ " << endl;
    cout << "\n    MINI\nSPREADSHEET\n\n\t\t\t\tA C++ program by Sanchit Sayala ." << endl << "\t\t\t\t   (Press any key to start)";
    getch ();
    clrscr();
    for (int ss=0; ;ss++)
        Menu();

}


//                  ******************************************************************************************
//
//                                  Function to show menu.
//
//                  ******************************************************************************************

void Menu ()
{
    clrscr();
    char opt;
    clrscr();
	cout << "                *******************************************       " << endl;
	cout << "                *    **   **  *******  *    *  *    *     *       " << endl;
	cout << "                *    * * * *  *        **   *  *    *     *       " << endl;
	cout << "                *    *  *  *  *****    *  * *  *    *     *       " << endl;
	cout << "                *    *     *  *        *   **  *    *     *       " << endl;
	cout << "                *    *     *  *******  *    *  ******     *       " << endl;
	cout << "                *  ####################################   *       " << endl;
	cout << "                *******************************************       " << endl << endl << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	cout << "---------------------------------------------------------------------------" << endl << endl;
		cout << "\t\t\t(N)ew\n\t\t\t(O)pen\n\t\t\t(D)elete\n\t\t\t(H)elp\n\t\t\t(E)xit\nEnter your choice: "<< endl;
	cout << "---------------------------------------------------------------------------" << endl;
	cout << "---------------------------------------------------------------------------" << endl << endl;
		opt=getch();
		switch(opt)
		{
		    case 'n':
			case 'N':
			{
			    clrscr();
				Create();
				getch();
				break;
			}
			case 'o':
			case 'O':
			{
			    clrscr();
				Open();
				getch();
				break;
			}
			case 'd':
			case 'D':
			{
			    clrscr();
				Delete();
				getch();
				break;
			}
			case 'h':
			case 'H':
			{
			    clrscr();
				Help();
				getch();
				break;
			}
			case 'e':
			case 'E':
			{
				exit(0);
			}
			default:
			{
				cout<<"Wrong Choice....";
				getch();
				clrscr();
			}
		}
}


//                  ******************************************************************************************
//
//                                  Function to create table.
//
//                  ******************************************************************************************

void Create()
{
	fil.open("newfile.dat",ios::out| ios::binary| ios::app);
		fileobj.Input();
		fileobj.Output();
		char choice;
    cout << "---------------------------------------------------------------------------" << endl;
	cout << "---------------------------------------------------------------------------" << endl << endl;
    cout << "\t\t(S)ave\n\t\t(E)dit\n\t\t(B)ack to menu\nEnter your choice: "<< endl;
    cout << "---------------------------------------------------------------------------" << endl;
	cout << "---------------------------------------------------------------------------" << endl << endl;
    choice=getch();
    switch(choice)
    {
    case 's':
    case 'S':
	{
    fil.write((char*)&fileobj, sizeof(fileobj));
    fil.close();
    cout << "File Saved !!!!!\n";
	break;
	}
	case 'e':
    case 'E':
    {
	fil.close();
	Edit(0,NULL);
	break;
    }
    case 'b':
    case 'B':
    {
	fil.close();
	Menu();
	break;
    }
    }
}


//                  ******************************************************************************************
//
//                                  Function to open a saved table.
//
//                  ******************************************************************************************

void Open()
{
    int check=0;
    fil.open("newfile.dat",ios::in| ios::binary);
	if(!fil)
	{
		cout<<"No files saved." << endl;
	}
	else
	{
	    cout << "Saved files:" << endl;
		fil.read((char*)&fileobj, sizeof(fileobj));
		while(!fil.eof())
		{
			cout<< fileobj.name <<endl;
			check=1;
			fil.read((char*)&fileobj, sizeof(fileobj));
		}
	}
	fil.close();
	if (check==0)
	cout << "No files saved." << endl;
    else
    {
    check=0;
    ifstream f;
	char n[100];
	cout<<"Enter name of file to be opened:";
	gets(n);
	fil.open("newfile.dat",ios::in| ios::binary);
		fil.read((char*)&fileobj, sizeof(fileobj));
		while(!fil.eof())
		{
			if(strcmp(n,fileobj.getn())==0)
			{
				fileobj.Output();
				check=1;
			}
			fil.read((char*)&fileobj, sizeof(fileobj));
		}
	fil.close();
	char choice;
	cout << "Edit file ??? y/n" <<endl;
	choice=getch();
	if (choice=='y'||choice=='Y')
    {
    Edit(1,n);
    }
	if (check==0)
	cout << "No such file exist." << endl;
    }
}


//                  ******************************************************************************************
//
//                                  Function to edit previously entered data.
//
//                  ******************************************************************************************


void Edit(int saved, char nm[])
{
    if (saved==1)
    {
    ofstream o;
	o.open("temp.dat",ios::out|ios::binary);
	fil.open("newfile.dat",ios::in| ios::binary);
		fil.read((char*)&fileobj, sizeof(fileobj));
		while(!fil.eof())
		{
			if(strcmp(nm,fileobj.getn())!=0)
			{
				o.write((char*)&fileobj, sizeof(file));
			}
			fil.read((char*)&fileobj, sizeof(fileobj));
		}
	o.close();
	fil.close();
	remove("newfile.dat");
	rename("temp.dat", "newfile.dat");
    }
    editing:
    cout << "Please note down the row and column number to be edited (use h instead of column number for editing).\nPress any key to view the table." << endl;
    getch();
    fileobj.Output();
    char row,col,changes;
    clrscr();
    cout << "Enter the row number to be edited (use h instead of column number for editing). " << endl;
    cin >> row;
    cout << "Enter the column number to be edited" << endl;
    cin >> col;
    if (isdigit(row)&&isdigit(col))
    {
	cout << "Replace " << fileobj.a[row-'0'][(col-'0')-1] << " by: ";
	gets(fileobj.a[row-'0'][(col-'0')-1]);
    }
    else if (row=='h'&&isdigit(col))
    {
	cout << "Replace " << fileobj.a[0][col-'0'] << " by: ";
	gets(fileobj.a[0][col-'0']);
    }
    else
    {
	cout << "Invalid Entry.";
	getch();
	goto editing;
    }
    fileobj.Output();
    cout << "More changes ??? (y/n)" << endl;
    changes=getch();
    if (changes=='y'||changes=='y')
	goto editing;
    if (saved==1)
    {
    fil.open("newfile.dat",ios::out| ios::binary| ios::app);
    fil.write((char*)&fileobj, sizeof(fileobj));
    fil.close();
    }
    else
    {
    char choice;
    cout << "---------------------------------------------------------------------------" << endl;
	cout << "---------------------------------------------------------------------------" << endl << endl;
    cout << "\t\t(S)ave\n\t\t(E)dit\n\t\t(B)ack to menu\nEnter your choice: "<< endl;
    cout << "---------------------------------------------------------------------------" << endl;
	cout << "---------------------------------------------------------------------------" << endl << endl;
    choice=getch();
    switch(choice)
    {
    case 's':
    case 'S':
	{
    fil.open("newfile.dat",ios::out| ios::binary| ios::app);
    fil.write((char*)&fileobj, sizeof(fileobj));
    fil.close();
    cout << "File Saved !!!!!\n";
	break;
	}
	case 'e':
    case 'E':
    {
	Edit(0,NULL);
	break;
    }
    case 'b':
    case 'B':
    {
	Menu();
	break;
    }
    }
    }
}


//                  ******************************************************************************************
//
//                                  Function to show help.
//
//                  ******************************************************************************************

void Help()
{
     char help;
    cout << "---------------------------------------------------------------------------" << endl;
	cout << "---------------------------------------------------------------------------" << endl << endl;
    cout << "\t\t(A)bout\n\t\t(F)ormulas\n" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
	cout << "---------------------------------------------------------------------------" << endl << endl;
    help=getch();
    switch(help)
    {
        case 'a':
        case 'A':clrscr();cout << "\t\t\t\tAbout MINI SPREADSHEET\n\n\n\n\n\nThe program is for the tabulation of the data. The data is entered by the user row-wise. It is done according to the names of the columns as provided by the user. The user can save the table, open the saved tables, edit them and delete them. The program also provides some formulas for calculations and easier usage of the program.";break;
        case 'f':
        case 'F':
        {
        clrscr();
        cout << "Formulas that can be used:\n";
        cout << "1.ADDITION\n$$add(1,2,3,....):-Sum of columns 1,2,3,....\n";
        cout << "2.SUBTRACTION\n$$sub(1,2):-Difference of columns 2 and 1 i.e.(col_2-col_1)\n";
        cout << "3.MULTIPLICATION\n$$mul(1,2,3,....):-Product of columns 1,2,3,....\n";
        cout << "4.DIVISION\n$$div(1,2):-Division of columns 2 and 1 i.e.(col_2/col_1)\n";
        cout << "5.AVERAGE\n$$avg(1,2,3,....):-Average of columns 1,2,3,....\n";
        cout << "6.EDIT ENTERED DATA\n$$edit(1,2):-Edit the data of cell with row#1 and column#2.\n$$edit(h,1):-Edit the data of heading#1.\n";
        cout << "7.VIEW THE TABLE\n$$view:-View the table.\n";
        cout << "8.COPY THE DATA\n$$cpy(1):-Copy the data from column#1.\n";
        cout << "\t\tNOTE :All the calculations are for integer type.";
        }
    }
    getch();
    Menu();
}


//                  ******************************************************************************************
//
//                                  Function to delete saved table.
//
//                  ******************************************************************************************

void Delete()
{
    int check=0;
    fil.open("newfile.dat",ios::in| ios::binary);
	if(!fil)
	{
		cout<<"No files saved." << endl;
	}
	else
	{
	    cout << "Saved files:" << endl;
		fil.read((char*)&fileobj, sizeof(fileobj));
		while(!fil.eof())
		{
			cout<< fileobj.name <<endl;
			check=1;
			fil.read((char*)&fileobj, sizeof(fileobj));
		}
	}
	fil.close();
	if (check==0)
        cout << "No files saved." << endl;
    else
    {
    check=0;
    ifstream f;
	char n[100];
	cout<<"Enter the name of file to be deleted :";
	gets(n);
	ofstream o;
	o.open("temp.dat",ios::out|ios::binary);
	fil.open("newfile.dat",ios::in| ios::binary);
		fil.read((char*)&fileobj, sizeof(fileobj));
		while(!fil.eof())
		{
			if(strcmp(n,fileobj.getn())!=0)
			{
				o.write((char*)&fileobj, sizeof(fileobj));
				check=1;
			}
			fil.read((char*)&fileobj, sizeof(fileobj));
		}
	o.close();
	fil.close();
	remove("newfile.dat");
	rename("temp.dat", "newfile.dat");
		if (check==0)
        cout << "No such file exist." << endl;
    }
}

//                  ******************************************************************************************
//
//                                  End of the program.
//
//                  ******************************************************************************************
