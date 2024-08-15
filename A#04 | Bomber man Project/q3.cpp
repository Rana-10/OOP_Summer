// Muhammad Azmat
// Assignment 04
// 23i-2651
// OOP-B

#include <iostream>
#include <string>

using namespace std;

class hospital_member
{
protected:
    string id;
    string name;
    int age;
    string gender;

public:
    hospital_member()
    {
    }

    hospital_member(string id, string name, int age, string gender)
    {
        this->id = id;
        this->name = name;
        this->age = age;
        this->gender = gender;
    }

    string get_id()
    {
        return id;
    }
    string get_name()
    {
        return name;
    }
    int get_age()
    {
        return age;
    }
    string get_gender()
    {
        return gender;
    }

    void set_id(string id)
    {
        this->id = id;
    }
    void set_name(string name)
    {
        this->name = name;
    }
    void set_age(int age)
    {

        this->age = age;
    }
    void set_gender(string gender)
    {
        this->gender = gender;
    }

    virtual void display_deets()
    {
        cout << "ID: " << id << "  Name: " << name << "  Age: " << age << "  Gender: " << gender << endl;
    }

    virtual ~hospital_member()
    {
    }
};

class Doctor : public hospital_member
{
private:
    string specialization;
    string availability;

public:
    Doctor()
    {
    }
    Doctor(string id, string name, int age, string gender, string spec, string avail)
        : hospital_member(id, name, age, gender)
    {
        specialization = spec;
        availability = avail;
    }

    string get_specialization()
    {
        return specialization;
    }
    string get_availability()
    {
        return availability;
    }

    void set_specialization(string spec)
    {
        specialization = spec;
    }
    void set_availability(string avail)
    {
        availability = avail;
    }

    void display_deets() override
    {
        hospital_member::display_deets();
        cout << "Specialization: " << specialization << "  Availability: " << availability << endl;
    }
};

class Nurse : public hospital_member
{
private:
    int years_of_exp;
    string shift;

public:
    Nurse(string id, string name, int age, string gender, int exp, string sh)
        : hospital_member(id, name, age, gender)
    {
        years_of_exp = exp;
        shift = sh;
    }

    int get_exp_years()
    {
        return years_of_exp;
    }
    string get_shift()
    {
        return shift;
    }

    void set_exp_years(int exp)
    {
        years_of_exp = exp;
    }
    void set_shift(string sh)
    {
        shift = sh;
    }

    void display_deets() override
    {
        hospital_member::display_deets();
        cout << "Experience Years: " << years_of_exp << ", Shift: " << shift << endl;
    }
};

class Patient : public hospital_member
{
private:
    string disease;
    string admission_date;

public:
    Patient(string id, string name, int age, string gender, string dis, string admis)
        : hospital_member(id, name, age, gender)
    {
        disease = dis;

        admission_date = admis;
    }

    string get_disease()
    {
        return disease;
    }
    string get_admission_date()
    {
        return admission_date;
    }

    void set_disease(string &disease)
    {
        this->disease = disease;
    }
    void set_admission_date(string &admission)
    {
        admission_date = admission;
    }

    void display_deets() override
    {
        hospital_member::display_deets();
        cout << "Disease: " << disease << ", Admission Date: " << admission_date << endl;
    }
};

// Hospital class
class Hospital
{
private:
    hospital_member **members;
    int count;
    int total_capacity;

public:
    Hospital()
    {
        count = 0;
        total_capacity = 0;
        members = new hospital_member *[total_capacity];
    }
    void resize()
    {
        // suppose we have to resize it to have just 2 members in hospital
        total_capacity = 2;
        hospital_member **newMembers = new hospital_member *[total_capacity];
        for (int i = 0; i < count; ++i)
        {
            newMembers[i] = members[i];
        }
        delete[] members;
        members = newMembers;
    }

    void addMember(hospital_member *member)
    {
        if (count == total_capacity)
        {
            resize();
        }
        members[count++] = member;
    }

    void removeMember(string id)
    {
        for (int i = 0; i < count; ++i)
        {
            if (members[i]->get_id() == id)
            {
                delete members[i];
                for (int j = i; j < count - 1; ++j)
                {
                    members[j] = members[j + 1];
                }
                --count;
                return;
            }
        }
        cout << "Member not found." << endl;
    }

    void display_all_members()
    {
        for (int i = 0; i < count; ++i)
        {
            members[i]->display_deets();
            cout << endl;
        }
    }

    hospital_member *find_member_by_id(string id)
    {
        for (int i = 0; i < count; ++i)
        {
            if (members[i]->get_id() == id)
            {
                return members[i];
            }
        }
    }
    hospital_member *find_member_by_name(string name)
    {
        for (int i = 0; i < count; ++i)
        {
            if (members[i]->get_name() == name)
            {
                return members[i];
            }
        }
        return nullptr;
    }

    void sort_by_name()
    {
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (members[i]->get_name() > members[j]->get_name())
                {
                    // swapping using temp
                    hospital_member *temp = members[i];
                    members[i] = members[j];
                    members[j] = temp;
                }
            }
        }
    }

    void sort_by_age()
    {
        // selection sort
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (members[i]->get_age() > members[j]->get_age())
                {
                    // exchange
                    hospital_member *temp = members[i];
                    members[i] = members[j];
                    members[j] = temp;
                }
            }
        }
    }

    void recommendDoctors(string specialization)
    {
        for (int i = 0; i < count; ++i)
        {
            Doctor *doc = dynamic_cast<Doctor *>(members[i]);
            if (doc->get_specialization() == specialization)
            {
                doc->display_deets();
                cout << endl;
            }
        }
    }
    ~Hospital()
    {
        for (int i = 0; i < count; ++i)
        {
            delete members[i];
        }
        delete[] members;
    }
};

int main()
{
    Hospital hospital;

    Doctor *doc2 = new Doctor("D2", "Azmat", 50, "Male", "Neurology", "10 AM - 6 PM");
    Nurse *nurse1 = new Nurse("N1", "Mahnoor", 30, "Female", 5, "Day");

    Patient *patient1 = new Patient("P1", "Haroon", 60, "Female", "Flu", "2024-07-01");

    hospital.addMember(doc2);
    hospital.addMember(nurse1);

    hospital.addMember(patient1);

    cout << "All the members in the hospital:" << endl;
    hospital.display_all_members();

    cout << "Now, Finding member by name Azmat" << endl;
    hospital.find_member_by_name("Azmat")->display_deets();

    cout << "Finding member by ID (P1):" << endl;
    hospital.find_member_by_id("P1")->display_deets();

    cout << "Sorting members by name:" << endl;
    cout << endl;
    cout << endl;
    hospital.sort_by_name();
    hospital.display_all_members();

    cout << "Sorting members by age:" << endl;
    hospital.sort_by_age();
    hospital.display_all_members();

    cout << "Removing member with ID (N1):" << endl;
    hospital.removeMember("N1");
    hospital.display_all_members();
    cout << endl;
    cout << "Doctors specialized in Neurology:" << endl;
    hospital.recommendDoctors("Neurology");
    return 0;
}
