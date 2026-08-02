#include<iostream>
#include <vector>
using namespace std;
class Person
{
	private:
	string name;
	short int age;
	public:
	Person(string n="",int a=0)
	{
		name=n;
		age=a;	
	}
	void setName(string n)
	{
		name=n;
	}
	void setAge(int a)
	{
		age=a;
	}
	string getName()
	{
		return name;
	}
	short int getAge()
	{
		return age;
	}
	~Person() {}
};

class Patient: public Person
{
	private:
	short int patientID;
	static short int counter;
	string disease;
	short int doctorID;
	public:
	Patient (string n="",short int a=0,short int pID=0,string d=""):Person(n,a)
	{
		patientID=++counter;
		disease=d;
		doctorID=0;
	}
	short int getPateintID()
	{
		return patientID;
	}
	string getDisease()
	{
		return disease;
	}
	void assignDoctor(short int dID)
	{
		doctorID=dID;
	}
	short int getDoctorID()
	{
		return doctorID;
	}
	~Patient()
	{
	}
};
short int Patient::counter=0;

class Doctor:public Person
{
	private:
	short int doctorID;
	static short int counter;
	string specialization;
	public:
	Doctor (string n="",short int a=0,short int dID=0,string spec=""):Person(n,a)
	{
		doctorID=++counter;
		specialization=spec;
	}
	short int getDoctorID()
	{
		return doctorID;
	}
	string getSpecialization()
	{
		return specialization;
	}
	~Doctor() {}
};
short int Doctor::counter=0;

class Appointment
{
	private:
	short int patientID;
    short int doctorID;
	string date;
	string time;
	public:
	Appointment(short int pID=0,short int dID=0,string d="",string t="")
	{
		patientID=pID;
		doctorID=dID;
		date=d;
		time=t;
	}
	Appointment(short int pID,short int dID, string d)
	{
        patientID=pID;
        doctorID=dID;
        date=d;
        time="Not Assigned";
    }
	short int getPatientID()
	{
		return patientID;
	}
	short int getDoctorID()
	{
		return doctorID;
	}
	void display()
	{
        cout<<"Patient ID: "<< patientID<<" Doctor ID: "<< doctorID<<" Date: "<< date
        << " Time: " << time << endl;
    }
    ~Appointment(){}
};

class Bill
{
	private:
	short int patientID;
	float consultationFee;
    float medicineCharges;
	public:
	Bill (short int pID=0,float cF=0,float mC=0)
	{
		patientID=pID;
		consultationFee=cF;
		medicineCharges=mC;
	}
	short int getPatientID()
	{
		return patientID;
	}
	float getTotal()
	{
        return consultationFee + medicineCharges;
    }
	Bill operator+(Bill b)
	{
    return Bill(patientID,consultationFee + b.consultationFee,medicineCharges + b.medicineCharges);
	}
	void display()
	{
        cout<<"Patient ID: "<<patientID<<endl;
        cout<<"Consultation Fee: "<<consultationFee<<endl;
        cout<<"Medicine Charges: "<<medicineCharges<<endl;
        cout<<"Total Bill: "<<getTotal()<<endl;
    }
    ~Bill(){}
};

class HospitalSystem
{
	private:
	vector<Patient> patients;
	vector<Doctor> doctors;
	vector<Appointment> appointments;
	vector<Bill> bills;
	public:
	void addPatient (Patient p)
	{
		patients.push_back(p);
	}
	void addDoctor (Doctor d)
	{
		doctors.push_back(d);
	}
	void createAppointment(Appointment a)
	{
		bool pFound=false,dFound=false;

		for(int i=0;i<patients.size();i++)
		{
			if(patients[i].getPateintID()==a.getPatientID())
			{
				pFound=true;
			}
		}

		for(int i=0;i<doctors.size();i++)
		{
			if(doctors[i].getDoctorID()==a.getDoctorID())
			{
				dFound=true;
			}
		}

		if(pFound && dFound)
		{
			appointments.push_back(a);
			cout<<"Appointment Created Successfully"<<endl;
		}
		else
		{
			cout<<"Invalid Patient or Doctor ID"<<endl;
		}
    }
	void addBill(Bill b)
	{
		for(int i=0;i<patients.size();i++)
		{
			if(patients[i].getPateintID()==b.getPatientID())
			{
				bills.push_back(b);
			}
		}
	}
	void assignDoctor(short int pID, short int dID)
	{
		for(int i=0;i<patients.size();i++)
		{
			if(patients[i].getPateintID()==pID)
			{
				patients[i].assignDoctor(dID);
			}
		}
	}
	void showDoctorByID(short int id)
	{
		for(int i=0;i<doctors.size();i++)
		{
			if(doctors[i].getDoctorID()==id)
			{
				cout<<"Doctor Found"<<endl;
				cout<<"ID: "<<doctors[i].getDoctorID()<<endl;
				cout<<"Name: "<<doctors[i].getName()<<endl;
				cout<<"Specialization: "<<doctors[i].getSpecialization()<<endl;
				return;
			}
		}
		cout<<"Doctor Not Found"<<endl;
	}
	void showPatients()
	{
		for(int i=0;i<patients.size();i++)
		{
			cout << "\n------Patients List------\n";
			cout<<"ID : "<<patients[i].getPateintID()<<endl;
			cout<<"Name : "<<patients[i].getName()<<endl;
			cout<<"Disease : "<<patients[i].getDisease()<<endl;
			cout<<"Doctor ID : "<<patients[i].getDoctorID()<<endl;
		}
	}
	void showDoctors()
	{
		for(int i=0;i<doctors.size();i++)
		{
			cout << "\n------Doctors List------\n";
			cout<<"ID: "<<doctors[i].getDoctorID()<<endl;
			cout<<"Name:"<<doctors[i].getName()<<endl;
			cout<<"Specialization: "<<doctors[i].getSpecialization()<<endl;
		}
	}
	void showAppointments()
	{
		for(int i=0;i<appointments.size();i++)
		{
			appointments[i].display();
		}
	}
	void showBills()
	{
		for(int i=0;i<bills.size();i++)
		{
			bills[i].display();
		}
	}
	void showPatientRecord()
	{
		for(int i=0;i<patients.size();i++)
		{
			cout << "\n--------Complete Patient Record--------\n";
			cout<<"ID : "<<patients[i].getPateintID()<<endl;
			cout<<"Name : "<<patients[i].getName()<<endl;
			cout<<"Disease : "<<patients[i].getDisease()<<endl;
			cout<<"Doctor ID : "<<patients[i].getDoctorID()<<endl;
		}
	}
	~HospitalSystem(){}
};

int main()
{
	HospitalSystem system;
	short int choice;
	do
	{
	cout<<"--------Smart Healthcare Patient & Billing System--------"<<endl;
	cout<<"1. Add Patient\n"
	<<"2. Add Doctor\n"
	<<"3. Assign Doctor to Patient\n"
	<<"4. Create Appointment\n"
	<<"5. Generate Bill\n"
	<<"6. Show Patients\n"
	<<"7. Show Doctors\n"
	<<"8. Show Appointments\n"
	<<"9. Show Bills\n"
	<<"10. Show Patient Record\n"
	<<"11. Show Doctor By ID\n"
	<<"12. Exit\n";
	cout<<"Enter your choice : "<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
		string name, disease;
        int age, id;
        cout<<"Enter Name: "; 
		cin>>name;
        cout<<"Enter Age: "; 
		cin>>age;
        cout<<"Enter Disease: "; 
		cin>>disease;
        Patient p(name, age, id, disease);
        system.addPatient(p);
		break;
		}
		case 2:
		{
		string name, spec;
        int age, id;
        cout<<"Enter Name: ";
		 cin>>name;
        cout<<"Enter Age: "; 
		cin>>age;
        cout<<"Enter Specialization: "; 
		cin>>spec;
        Doctor d(name, age, id, spec);
        system.addDoctor(d);
		break;
		}
		case 3:
		{
		int pID,dID;
		cout<<"Enter Patient ID: "; 
		cin>>pID;
		cout<<"Enter Doctor ID: "; 
		cin>>dID;
		system.assignDoctor(pID,dID);
		break;
		}
		case 4:
		{
		int pID,dID;
		string date,time;
		cout<<"Enter Patient ID: "; 
		cin>>pID;
		cout<<"Enter Doctor ID: "; 
		cin>>dID;
		cout<<"Enter Date: "; 
		cin>>date;
		cout<<"Enter Time: "; 
		cin>>time;
		Appointment a(pID,dID,date,time);
		system.createAppointment(a);
		break;
		}
		case 5:
		{
		int pID;
		float c=0,m=0;
		char choiceMed;
		cout<<"Enter Patient ID: "; 
		cin>>pID;
		cout<<"Enter Consultation Fee: "; 
		cin>>c;
		cout<<"Does patient have medicine? (y/n): ";
		cin>>choiceMed;
		if(choiceMed=='y' || choiceMed=='Y')
		{
			cout<<"Enter Medicine Charges: ";
			 cin>>m;
			Bill b1(pID,c,0);
			Bill b2(pID,0,m);
			Bill total = b1 + b2;
			system.addBill(total);
		}
		else
		{
			Bill b(pID,c,0);
			system.addBill(b);
		}
		break;
		}
		case 6:
		system.showPatients();
		break;
		case 7:
		system.showDoctors();
		break;
		case 8:
		system.showAppointments();
		break;
		case 9:
		system.showBills();
		break;
		case 10:
		system.showPatientRecord();
		break;
		case 11:
		{
		int id;
		cout<<"Enter Doctor ID: ";
		cin>>id;
		system.showDoctorByID(id);
		break;
		}
		case 12:
		cout<<"Exiting..........";
		break;
		default:
		cout<<"Invalid Choice"<<endl;
	}
	}while(choice!=12);

	return 0;
}
