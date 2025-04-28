// zookeeperChallenge.cpp
// Brenton Ramirez-Vargas
// dh 04/02/2025
// demo for CIT-66



#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
using namespace std;


// Base
class animal {
    protected:
        string id;
        string species;
        string name;
        int age;
        string sex;
        string color;
        string weight;
        string birth_date;
        string origin;
        string arrival_date;


    public:
    // Constructor
        animal(string id, string species, string name, int age, string sex, string color, string weight,
            string birth_date, string origin, string arrival_date) {
        this->id = id;
        this->species = species;
        this->name = name;
        this->age = age;
        this->sex = sex;
        this->color = color;
        this->weight = weight;
        this->birth_date = birth_date;
        this->origin = origin;
        this->arrival_date = arrival_date;
        }

    //Getters
        string getId() {return id;};
        string get_species() {return species;};
        string get_name() { return name; }
        int get_age() { return age; }
        string get_sex() {return sex; }
        string get_color() { return color; }
        string get_weight() { return weight; }
        string get_birth_date() { return birth_date; }
        string get_origin() { return origin; }
        string get_arrival_date() { return arrival_date; }

    //Setters
        void set_id(string id) { this->id = id; }
        void setSpecies(string species) { this->species = species; }
        void setName(string name) { this->name = name; }
        void setAge(int age) { this->age = age; }
        void setSex (string sex) {this->sex = sex; }
        void setColor (string color) {this->color = color; }
        void setWeight(string weight) {this->weight = weight; }
        void setBirthDate (string birthdate) {this->birth_date = birthdate; }
        void setOrigin (string origin) {this->origin = origin; }
        void setArrivalDate (string arrivaldate) {this->arrival_date = arrivaldate; }

    // Displaying Info
    virtual void displayInfo() const {
        cout << this->id << "" << this->species << " " << this->name << " " << this->age
        << this->sex << " " << this->color << " " << this->weight << " " << this->birth_date << " "
            << this->origin << " " << this->arrival_date << " " << endl;
        }

    //Destructor
        virtual ~animal() {}
};

// Subclasses
    class Hyena : public animal {
        public:
        Hyena (string id, string species, string name, int age, string sex, string color, string weight,
            string birth_date, string origin, string arrival_date):
        animal (id, species, name, age, sex, color, weight, birth_date, origin, arrival_date) {
            this->name = name;
            this->age = age;
            this->sex = sex;
            this->color = color;
            this->weight = weight;
            this->birth_date = birth_date;
            this->origin = origin;
            this->arrival_date = arrival_date;
        }
    };

        class Lion : public animal {
        public:
        Lion (string id, string species, string name, int age, string sex, string color, string weight,
            string birth_date, string origin, string arrival_date):
        animal (id, species, name, age, sex, color, weight, birth_date, origin, arrival_date) {
            this->name = name;
            this->age = age;
            this->sex = sex;
            this->color = color;
            this->weight = weight;
            this->birth_date = birth_date;
            this->origin = origin;
            this->arrival_date = arrival_date;
        }
    };
    class Bear : public animal {
    public:
        Bear (string id, string species, string name, int age, string sex, string color, string weight,
            string birth_date, string origin, string arrival_date):
        animal (id, species, name, age, sex, color, weight, birth_date, origin, arrival_date) {
            this->name = name;
            this->age = age;
            this->sex = sex;
            this->color = color;
            this->weight = weight;
            this->birth_date = birth_date;
            this->origin = origin;
            this->arrival_date = arrival_date;
        }
    };
    class Tiger : public animal {
    public:
        Tiger (string id, string species, string name, int age, string sex, string color, string weight,
            string birth_date, string origin, string arrival_date):
        animal (id, species, name, age, sex, color, weight, birth_date, origin, arrival_date) {
            this->name = name;
            this->age = age;
            this->sex = sex;
            this->color = color;
            this->weight = weight;
            this->birth_date = birth_date;
            this->origin = origin;
            this->arrival_date = arrival_date;
        }
    };

string generateBirthDate(int age, const string& season) {
    int year = 2024 - age;
    string month_day;
    if (season == "spring") month_day = "-03-15";
    else if (season == "summer") month_day = "-06-15";
    else if (season == "fall") month_day = "-09-15";
    else if (season == "winter") month_day = "-12-15";
    else month_day = "-01-01"; // fallback
    return to_string(year) + month_day;
};

int calculateAge(const string& birth_date, const string& current_date = "2024-03-05") {
    std::tm birth = {}, current = {};
    istringstream ss_birth(birth_date), ss_current(current_date);
    ss_birth >> get_time(&birth, "%Y-%m-%d");
    ss_current >> get_time(&current, "%Y-%m-%d");

    int age = current.tm_year - birth.tm_year;
    if ((current.tm_mon < birth.tm_mon) ||
        (current.tm_mon == birth.tm_mon && current.tm_mday < birth.tm_mday)) {
        age--;
        }
    return age;
};

    map<string, int> speciesCounts;  // Global or passed by reference

    string genUniqueID(const string& species) {
        string prefix;
        if (species == "hyena") prefix = "Hy";
        else if (species == "lion") prefix = "Li";
        else if (species == "tiger") prefix = "Ti";
        else if (species == "bear") prefix = "Be";
        else prefix = "Un";  // Unknown

    speciesCounts[species]++;  // Increment count for that species
    ostringstream oss;
    oss << prefix << setw(2) << setfill('0') << speciesCounts[species];

    return oss.str();
}


int main() {

        cout << "\nWelcome to the Fresno City Zoo!\n"
        "We are excited to have you here with us today.\n"
        "Below are details of our beloved animal-friends.\n"
        "Check to see if you share a name or birthday with our friends!\n"
        "\n\n\nPlease be polite and enjoy your visit!\n\n\n"
        "\n\n\nZoo Animal List:\n\n\n" <<endl;


        vector <string> animals;

    // Hardcoded animal data
    vector<tuple<string, int, string, string, int, string, string>> raw_data1 = {
        {"hyena", 4, "spring", "tan", 70, "female", "Friguia Park, Tunisia"},
        {"hyena", 12, "fall", "brown", 150, "male", "Friguia Park, Tunisia"},
        {"hyena", 4, "spring", "black", 120, "male", "Friguia Park, Tunisia"},
        {"hyena", 8, "unknown", "black and tan striped", 105, "female", "Friguia Park, Tunisia"},

        {"lion", 6, "spring", "tan", 300, "female", "Zanzibar, Tanzania"},
        {"lion", 12, "winter", "dark tan", 375, "female", "KopeLion, Tanzania"},
        {"lion", 22, "fall", "golden", 450, "male", "Zanzibar, Tanzania"},
        {"lion", 4, "spring", "tan and brown", 275, "female", "KopeLion, Tanzania"},

        {"tiger", 2, "spring", "gold and tan stripes", 270, "male", "Dhaka, Bangladesh"},
        {"tiger", 4, "spring", "black stripes", 400, "female", "Dhaka, Bangladesh"},
        {"tiger", 18, "fall", "gold and tan", 300, "male", "Bardia, Nepal"},
        {"tiger", 3, "spring", "black stripes", 285, "female", "Bardia, Nepal"},

        {"bear", 7, "spring", "brown", 320, "male", "Alaska Zoo, Alaska"},
        {"bear", 25, "spring", "black", 425, "female", "Woodland park Zoo, Washington"},
        {"bear", 4, "fall", "black", 355, "female", "Woodland park Zoo, Washington"},
        {"bear", 4, "spring", "brown", 405, "male", "Alaska Zoo, Alaska"}
    };
    map<string, vector<string>> animalNames = {
        {"hyena", {"Kamari", "Banzai", "Bud", "Wema"}},
        {"lion", {"Nala", "Elsa", "Simba", "Elsa"}},
        {"tiger", {"Ryker", "Amber", "Cuddles", "Cosimia"}},
        {"bear", {"Smokey", "Snuggles", "Lippy", "Yogi"}}
    };


    int hyenaCount = 1;
    cout << "Hyena Habitat:\n";

    for (const auto& entry : raw_data1) {
        string species;
        int age, weight;
        string season, color, sex, origin;
        tie(species, age, season, color, weight, sex, origin) = entry;

        if (species == "hyena") {
            string name = animalNames["hyena"].front(); // get first name
            animalNames["hyena"].erase(animalNames["hyena"].begin()); // remove it

            string birth_date = generateBirthDate(age, season);
            string id = genUniqueID(species);
            string arrival_date = "2024-03-05";

            Hyena hyena(id, species, name, age, sex, color, to_string(weight),
                birth_date, origin, arrival_date);

            // Output
            cout << hyena.getId() << "; " << hyena.get_name() << "; birth date " << hyena.get_birth_date() << "; "
                << "(age " << hyena.get_age() << "); " << hyena.get_color() << " color; " << hyena.get_sex() << "; "
                << hyena.get_weight() << " pounds; from " << hyena.get_origin() << "; arrived "
                << hyena.get_arrival_date() << "\n";
        }
    }
        cout << "\n\n\nLion Habitat:\n";
        for (const auto& entry : raw_data1) {
            string species;
            int age, weight;
            string season, color, sex, origin;
            tie(species, age, season, color, weight, sex, origin) = entry;

            if (species == "lion") {
                string name = animalNames["lion"].front();
                animalNames["lion"].erase(animalNames["lion"].begin());

                string birth_date = generateBirthDate(age, season);
                string id = genUniqueID(species);
                string arrival_date = "2024-03-05";

                Lion lion(id, species, name, age, sex, color, to_string(weight), birth_date,
                    origin, arrival_date);

                cout << lion.getId() << "; " << lion.get_name() << "; birth date " << lion.get_birth_date() << "; "
                     << "(age " << lion.get_age() << "); " << lion.get_color() << " color; " << lion.get_sex()
                    << "; " << lion.get_weight() << " pounds; from " << lion.get_origin() << "; arrived "
                    << lion.get_arrival_date() << "\n";
            }
        }
        cout << "\n\n\nTiger Habitat:\n";
        for (const auto& entry : raw_data1) {
            string species;
            int age, weight;
            string season, color, sex, origin;
            tie(species, age, season, color, weight, sex, origin) = entry;

            if (species == "tiger") {
                string name = animalNames["tiger"].front();
                animalNames["tiger"].erase(animalNames["tiger"].begin());

                string birth_date = generateBirthDate(age, season);
                string id = genUniqueID(species);
                string arrival_date = "2024-03-05";

                Tiger tiger(id, species, name, age, sex, color, to_string(weight), birth_date,
                    origin, arrival_date);

                cout << tiger.getId() << "; " << tiger.get_name() << "; birth date " << tiger.get_birth_date() << "; "
                    << "(age " << tiger.get_age() << "); " << tiger.get_color() << " color; " << tiger.get_sex() << "; "
                    << tiger.get_weight() << " pounds; from " << tiger.get_origin() << "; arrived "
                    << tiger.get_arrival_date() << "\n";
            }
        }
        cout << "\n\n\nBear Habitat:\n";
        for (const auto& entry : raw_data1) {
            string species;
            int age, weight;
            string season, color, sex, origin;
            tie(species, age, season, color, weight, sex, origin) = entry;

            if (species == "bear") {
                string name = animalNames["bear"].front();
                animalNames["bear"].erase(animalNames["bear"].begin());

                string birth_date = generateBirthDate(age, season);
                string id = genUniqueID(species);
                string arrival_date = "2024-03-05";

                Bear bear(id, species, name, age, sex, color, to_string(weight), birth_date,
                    origin, arrival_date);

                cout << bear.getId() << "; " << bear.get_name() << "; birth date " << bear.get_birth_date() << "; "
                    << "(age " << bear.get_age() << "); " << bear.get_color() << " color; " << bear.get_sex() << "; "
                    << bear.get_weight() << " pounds; from " << bear.get_origin() << "; arrived "
                    << bear.get_arrival_date() << "\n";
            }
        }



    return 0;
}