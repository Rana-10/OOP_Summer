// Assignment 02
// Muhammad Azmat
// 23i-2651
// OOP-B

#include <iostream>
#include <string>

using namespace std;

class car_rent
{
private:
    string id;
    string customer_name;
    string car_make_model;
    string pick_up_date;
    string return_date;
    int rent_duration;
    int rental_rate;
    int customer_age;
    string *total_cars;
    int cars_count;
    string *additional_perks;
    int perks;

public:
    car_rent()
    {
        id = "";
        customer_name = "";
        car_make_model = "";
        pick_up_date = "";
        return_date = "";
        rent_duration = 0;
        rental_rate = 1;
        customer_age = 1;
        cars_count = 5;
        perks = 4;
        total_cars = new string[cars_count]{"W140", "E46", "E63", "C63", "S63"};
        additional_perks = new string[perks]{"BabySeat", "Drinks", "TintedWindows", "LeatherSeats"};
    }

    ~car_rent()
    {
        delete[] total_cars;
        delete[] additional_perks;
    }

    car_rent(string _id, string customer_naam, string gadi_make_model, string pick_date, string wapsi_date, double rent_durationn, int customer_umer)
    {
        id = _id;
        customer_name = customer_naam;
        car_make_model = gadi_make_model;
        pick_up_date = pick_date;
        return_date = wapsi_date;
        rent_duration = rent_durationn;
        customer_age = customer_umer;
        cars_count = 5;
        perks = 4;
        total_cars = new string[cars_count]{"W140", "E46", "E63", "C63", "S63"};
        additional_perks = new string[perks]{"BabySeat", "Drinks", "TintedWindows", "LeatherSeats"};
    }

    bool is_alpha_numeric(char x)
    {
        if (x >= 'A' && x <= 'Z')
        {
            return true;
        }
        else
        {
            if (x >= 'a' && x <= 'z')
            {
                return true;
            }
            else
            {
                if (x >= '0' && x <= '9')
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }

    bool special_char(char x)
    {
        return !is_alpha_numeric(x);
    }

    bool validate_res_id(const string &id)
    {
        if (id.size() != 14) // will tell how many characters is the reservation ID
        {
            cout << "There are not 14 characters in the Reservation ID you entered. Try Again! " << endl;
            return false;
        }

        for (int i = 0; i < 8; ++i)
        {
            if (!is_alpha_numeric(id[i]))
            {
                cout << "The first 8 characters are not alphanumeric. Try Again! " << endl;
                return false;
            }
        }

        for (int i = 8; i < 10; ++i)
        {
            if (!special_char(id[i]))
            {
                cout << "The 9th & 10th characters have to be special characters. Try Again! " << endl;
                return false;
            }
        }

        int sum = 0;
        for (int i = 10; i < 14; ++i)
        {
            if (id[i] > '9' || id[i] < '0')
            {
                cout << "The last 4 characters of the Reservation ID are reserved to numbers only. Try Again! " << endl;
                return false;
            }
            sum += id[i] - '0';
        }

        if (sum >= 18)
        {
            cout << "The sum of the last 4 digits is greater than 18. Try Again! " << endl;
            return false;
        }

        return true;
    }

    bool validate_car_make_model_year(const string &obj)
    {
        for (int i = 0; i < cars_count; i++)
        {
            if (total_cars[i] == obj)
            {
                return true;
            }
        }
        return false;
    }

    int calc_rental_rate(const string &obj, int agee)
    {
        int rate_per_hr = 20; // 20 dollars
        int p1 = 1;
        int p2 = 1;
        int p3 = 1;
        int p4 = 1;
        int p5 = 1;
        if (agee < 18)
        {
            rate_per_hr = 40;
        }

        if (obj == total_cars[0]) // w140
        {
            p1 = rate_per_hr * 2;
            return p1;
        }

        if (obj == total_cars[1]) // e46
        {
            p2 = rate_per_hr * 3;
            return p2;
        }

        if (obj == total_cars[2]) // e63
        {
            p3 = rate_per_hr * 4;
            return p3;
        }

        if (obj == total_cars[3]) // c63
        {
            p4 = rate_per_hr * 5;
            return p4;
        }

        if (obj == total_cars[4]) // s63
        {
            p5 = rate_per_hr * 6;
            return p5;
        }
    }

    int calc_rental_total(const string &obj)
    {
        // we can extract the rental rate by calling the function, and then aus mein added services k charges ko plus kar do
        int rental_r = calc_rental_rate(car_make_model, customer_age);
        int total_cost = rental_r * rent_duration;

        for (int i = 0; i < perks; ++i)
        {
            if (additional_perks[i] == obj)
            {
                total_cost += 10;
            }
            else if (additional_perks[i] == obj)
            {
                total_cost += 20;
            }
            else if (additional_perks[i] == obj)
            {
                total_cost += 30;
            }
            else if (additional_perks[i] == obj)
            {
                total_cost += 40;
            }
        }

        return total_cost;
    }

    void get_reservation_deets()
    {
        cout << "Reservation ID: " << id << endl;
        cout << "Customer Name: " << customer_name << endl;
        cout << "Customer Age: " << customer_age << endl;
        cout << "Car Make, Model and Year: " << car_make_model << endl;
        cout << "Pickup Date: " << pick_up_date << endl;
        cout << "Return Date: " << return_date << endl;
        cout << "Rental Duration: " << rent_duration << " days " << endl;
        cout << "Rental Total: " << calc_rental_total("BabySeat") << endl;
    }

    void updateReservation(const string &new_pickup_date, const string &new_return_date, const string &new_car_make_model, double new_rental_duration)
    {
        pick_up_date = new_pickup_date;
        return_date = new_return_date;
        car_make_model = new_car_make_model;
        rent_duration = new_rental_duration;
    }
};

int main()
{

    car_rent shop01("2CJV1UH1##7811", "Hasnain", "E63", "July/26/2019", "July/16/2024", 10, 19);

    if (shop01.validate_res_id("2CJV1UH1##7811"))
    {
        shop01.get_reservation_deets();
    }

    // cout << endl;

    // shop01.updateReservation("July/17/2024", "Julsy/27/2024", "W140", 5);
    // if (shop01.validate_res_id("2CJV1UH1##7811"))
    // {
    //     shop01.get_reservation_deets();
    // }

    return 0;
}