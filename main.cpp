#include <iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<string.h>
using namespace std;

class patient {

protected:
   char name[30];
    char gender[30];
   char condition[60];
    char age [30];
    char id[10];
    char f[4];
    fstream obj;
    fstream obj2;
public:
/*validation*/

bool isvalidate( char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i])) {
            return false;
        }
    }
    return true;
}
/*add a patient */
     void add_patient()
    {

	 obj.open("patient.txt",ios::app);
        cout<<"Enter patient id : ";
        cin.getline(id,10);
        cout<<"Enter patient name : ";
        cin.getline(name,30);
        {
            int i=0;
            while(i<=10)
            {
               if(!isvalidate(name))

           {
              cout<<"invalid Enter again : "<<endl;
              cin.getline(name,30);
           }


           i++;
            }

        }
        cout<<"Enter patient age : ";
        cin.getline(age,30);
        cout<<"Enter patient gender : ";
        cin.getline(gender,30);
        cout<<"Enter check : ";
        cin.getline(f,4);
        cout<<"Enter patient condition : ";
        cin.getline(condition,60);


		  obj<<id<<'/'<<name<<'/'<<age<<'/'<<gender<<'/'<<f<<'/'<<condition<<endl;

		 cout<<" Data is stored successfully "<<endl;

		  obj.close();

    }


/* display patient's details */
void display ()
{


obj.open("patient.txt", ios::in);


 cout<<"\n"<<"id  | name | age | gender| examination |condition  \n";
    while(!obj.eof())
    {



        obj.getline(id,10,'/');
        obj.getline(name,30,'/');
        obj.getline(age,30,'/');
        obj.getline(gender,30,'/');
        obj.getline(f,4,'/');
        obj.getline(condition,30);
        cout<< id << "\t"<<name<<"\t"<<age<<"\t"<<gender<<"\t"<<f<<"\t"<<condition<<endl;
    }

obj.close();


}



/*   update patient details  */
void update_patient ()
{ char d[10];

  obj.open("patient.txt",ios::in);
  obj2.open("temp.txt",ios::out);

      cout<<"Enter id : ";
      cin.getline(d,10);

    while(!obj.eof())
    {
        obj.getline(id,10,'/');
        obj.getline(name,30,'/');
        obj.getline(age,30,'/');
        obj.getline(gender,30,'/');
        obj.getline(f,4,'/');
        obj.getline(condition,60);
        if(strcmp(d,id)==0)
        {

        cout<<"Enter the patient's condition : ";
        cin.getline(condition,60);
        char f[]="YES";

            obj2<<id<<'/'<<name<<'/'<<age<<'/'<<gender<<'/'<<f<<'/'<<condition<<endl;
        }
        else
         {
             obj2<<id<<'/'<<name<<'/'<<age<<'/'<<gender<<'/'<<f<<'/'<<condition<<endl;
         }


    }
   obj.close();
   obj2.close();
    obj.open("patient.txt",ios::out);
    obj2.open("temp.txt",ios::in);
     while(!obj2.eof())
    {
        obj2.getline(id,10,'/');
        obj2.getline(name,30,'/');
        obj2.getline(age,30,'/');
       obj2.getline(gender,30,'/');
         obj2.getline(f,4,'/');
        obj2.getline(condition,60);
            obj<<id<<'/'<<name<<'/'<<age<<'/'<<gender<<'/'<<f<<'/'<<condition<<endl;

        }
    obj.close();
    obj2.close();
    remove("temp.txt");
    cout<<endl<<"Done!"<<endl;
  }




/*delete patient*/
void delete_patient ()
{
    obj.open("patient.txt",ios::in);
    obj2.open("delete.txt",ios::out);
    char idd[10];

    cout<<"Enter id : ";
    cin.getline(idd,10);
    while(!obj.eof())
    {
         obj.getline(id,10,'/');
           obj.getline(name,30,'/');
        obj.getline(age,30,'/');
       obj.getline(gender,30,'/');
       obj.getline(f,4,'/');
        obj.getline(condition,60);

        if(strcmp(id,idd)==0||strcmp(id,idd)==-1)
        {
            continue;

        }
        else{

            obj2<<id<<'/'<<name<<'/'<<age<<'/'<<gender<<'/'<<f<<'/'<<condition<<endl;
        }
    }
    obj.close();
    obj2.close();
    obj.open("patient.txt",ios::out);
    obj2.open("delete.txt",ios::in);
    while(!obj2.eof())
    {
          obj2.getline(id,10,'/');
        obj2.getline(name,30,'/');
        obj2.getline(age,30,'/');
       obj2.getline(gender,30,'/');
       obj2.getline(f,4,'/');
        obj2.getline(condition,60);
       obj<<id<<'/'<<name<<'/'<<age<<'/'<<gender<<'/'<<f<<'/'<<condition<<endl;
    }
     obj.close();
    obj2.close();
    remove("delete.txt");
    cout<<"removed successfully ! "<<endl;


}

/* search about patient */

void search_patient ()
{
   obj.open("patient.txt",ios::in);

    char na[30];
    int x=0;
    cout<<"Enter the name of the patient : ";
    cin.getline(na,30);
    while(!obj.eof())
    {
        obj.getline(id,10,'/');
        obj.getline(name,30,'/');
        obj.getline(age,30,'/');
        obj.getline(gender,30,'/');
        obj.getline(f,4,'/');
        obj.getline(condition,60);
        if(strcmp(name,na)==0)
        {
            cout<<"Id : "<<id<<endl<<"Name : "<<name<<endl<<"Age : "<<age<<endl<<"Gender : "<<gender<<endl<<"Examination : "<<f<<endl<<"Condition : "<<condition<<endl;
            x++;
            break;
        }
    }
    if(x==0)
    {
        cout<<"not found !"<<endl;
    }
}



};



int main()
{
   cout<<"\t \t \t========================================="<<endl;
   cout<<"\t \t \t  ************"<<"Main Menu "<<"************" <<endl;
   cout<< "\t  \t \t  ****"<<" CLINIC MANAGEMENT SYSTEM "<<"****"<<endl;
   cout<<"\t \t \t=========================================="<<endl<<endl;

    while(true)
    {
    patient p;
  cout<<"       ====================================================    "<<endl<<endl;
  cout<<"                 Please select any option                      "<<endl<<endl;
  cout<<" 1-       Press (1) To add a patient                              "<<endl;
  cout<<" 2-       Press (2) To put the patient's condition                "<<endl;
  cout<<" 3-       Press (3) To search for a patient                       "<<endl;
  cout<<" 4-       Press (4) To display patients data                      "<<endl;
  cout<<" 5-       Press (5) To remove a patient                           "<<endl;
  cout<<" 6-       Press (6) To log out                                   "<<endl<<endl;
  cout<<"      =====================================================      "<<endl;

char n[2];
cin.getline(n,2);
 if(n[0]=='1')
 {
    p.add_patient();

 }
 if(n[0]=='2')
{
   p.update_patient();


}
else if(n[0]=='3')
{
     p.search_patient();

}
else if(n[0]=='4')
{
    p.display();
}
else if(n[0]=='5')
{
   p.delete_patient();
}
else if(n[0]=='6')
{
    return 0;
}

    }






    return 0;
}
