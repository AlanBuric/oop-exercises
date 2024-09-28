#include <iostream>
#include <string>

using namespace std;

// 1. Zadatak

class A {
   public:
      int a;
      int b;
      
      A(int x, int y) : a(x), b(y) {} 
};

class B : public A {
	public:
		B(int x, int y) : A(x, y) {
		}
		
		int umnozak() {
			return a * b;
		}
};

// 2. Zadatak

class Person {
	public:
		string name, surname;
		int age;
		
		Person(string name2, string surname2, int age2) : 
			name(name2), surname(surname2), age(age2) {
		}
		
		string getName() {
			return name;
		}
		
		string getSurname() {
			return surname;
		}
		
		int getAge() {
			return age;
		}
		
		void setName(string newName) {
			name = newName;
		}
		
		void setSurname(string newSurname) {
			surname = newSurname;
		}
		
		void setAge(int newAge) {
			age = newAge;
		}
		
		bool equals(const Person & other) {
			return name == other.name 
				&& surname == other.surname 
				&& age == other.age;
		}
};

class Student : public Person {
	public:
		string studentID;
		short int academicYear;
		
		Student(string name2, string surname2, 
			int age2, string studentID2, short int academicYear2) :
			Person(name2, surname2, age2), studentID(studentID2),
			academicYear(academicYear2) {
			}
		
		string getStudentID() {
			return studentID;
		}
		
		short int getAcademicYear() {
			return academicYear;
		}
		
		void setStudentID(string newStudentID) {
			studentID = newStudentID;
		}
		
		void setAcademicYear(short int newYear) {
			academicYear = newYear;
		}
		
		bool equals(const Student & other) {
			return studentID == other.studentID;
		}
};

class Teacher : public Person {
	public:
		string email, subject;
		double salary;
		
		Teacher(string newName, string newSurname, int newAge, 
			string newEmail, string newSubject, double newSalary) : 
			Person(newName, newSurname, newAge), 
			email(newEmail), subject(newSubject), salary(newSalary) {	
			}
		
		string getEmail() {
			return email;
		}
		
		string getSubject() {
			return subject;
		}
		
		double getSalary() {
			return salary;
		}
		
		void setEmail(string newEmail) {
			email = newEmail;
		}
		
		void setSubject(string newSubject) {
			subject = newSubject;
		}
		
		void setSalary(double newSalary) {
			salary = newSalary;
		}
		
		void increaseSalary(int percent) {
			// npr. za 5%: salary + salary * 0.05 <=> salary * 1.05
			salary *= (percent + 100) / 100.0;
		}
		
		bool equals(const Teacher & other) {
			return email == other.email;
		}
};

// 3. Zadatak

class Dessert {
	public:
		string name;
		double weight;
		int calories;
		
		Dessert(string newName, double newWeight, int newCalories) :
			name(newName), weight(newWeight), calories(newCalories) {
		}
		
		string getName() {
			return name;
		}
		
		double getWeight() {
			return weight;
		}
		
		int getCalories() {
			return calories;
		}
		
		string getDessertType() {
			return "dessert";
		}
		
		string toString() {
			return getDessertType() + "'" + getName() + "', " 
				+ to_string(getWeight()) + "g, " + to_string(getCalories()) + "cal";
		}
		
		void setName(string newName) {
			name = newName;
		}
		
		void setWeight(double newWeight) {
			weight = newWeight;
		}
		
		void setCalories(int newCalories) {
			calories = newCalories;
		}
};

class Cake : public Dessert {
	public:
		bool containsGluten;
		string cakeType;
		
		Cake(string newName, double newWeight, int newCalories,
			bool newContainsGluten, string newCakeType) : 
			Dessert(newName, newWeight, newCalories), containsGluten(newContainsGluten),
			cakeType(newCakeType) {
		}
		
		bool doesContainGluten() {
			return containsGluten;
		}
		
		string getCakeType() {
			return cakeType;
		}
		
		string getDessertType() {
			return "cake";
		}
		
		void setContainsGluten(bool newContainsGluten) {
			containsGluten = newContainsGluten;
		}
		
		void setCakeType(string newCakeType) {
			cakeType = newCakeType;
		}
		
		string toString() {
			return getCakeType() + " " + Dessert::toString()
				+ ", " + (doesContainGluten() ? "with" : "without") + " gluten";
		}
};

class IceCream : public Dessert {
	public:
		string flavour, color;
		
		IceCream(string newName, double newWeight, int newCalories,
			string newFlavour, string newColor) : 
			Dessert(newName, newWeight, newCalories), flavour(newFlavour),
			color(newColor) {
		}
		
		string getFlavour() {
			return flavour;
		}
		
		string getColor() {
			return color;
		}
		
		void setFlavour(string newFlavour) {
			flavour = newFlavour;
		}
		
		void setColor(string newColor) {
			color = newColor;
		}
		
		string getDessertType() {
			return "ice cream";
		}
		
		string toString() {
			return getColor() + " " + getFlavour() + " " + Dessert::toString();
		}
};

int main() {
	// 1. Zadatak
	A primjer1(5, 6);
	B primjer2(3, 8);
	
	cout << primjer1.a << " " << primjer1.b << endl
		<< primjer2.a << " "  << primjer2.b << endl
		<< primjer2.umnozak() << endl;
	
	// 2. Zadatak
	Person person("Alan", "Buric", 21);
	
	printf("%s %s %d\n", person.getName().c_str(), person.getSurname().c_str(), person.getAge());
	
	person.setAge(23);
	cout << person.getAge() << endl;
	
	Student student("Alan", "Buric", 21, "0303109482", 2);
	
	printf("%s %s %d %s %d", student.getName().c_str(), student.getSurname().c_str(), 
		student.getAge(), student.getStudentID().c_str(), student.getAcademicYear());
	
	student.setName("Alen");
	student.setStudentID("0333299381");
	
	printf("%s %s %d %s %d\n", student.getName().c_str(), student.getSurname().c_str(), 
		student.getAge(), student.getStudentID().c_str(), student.getAcademicYear());
	
	Teacher teacher("Ana", "Anic", 30, "ana.anic@prof.skole.hr", "Matematika", 1800);
	
	printf("%s %s %d %s %s %f\n", teacher.getName().c_str(), teacher.getSurname().c_str(), 
		teacher.getAge(), teacher.getEmail().c_str(), teacher.getSubject().c_str(),
		teacher.getSalary());
		
	teacher.increaseSalary(15);
	
	cout << teacher.getSalary() << endl;
	
	// 3. Zadatak
	Cake cake("Ferrero", 953.8, 1572, true, "birthday");
	
	printf("%s %f %d %d %s\n", cake.getName().c_str(), cake.getWeight(), 
		cake.getCalories(), cake.doesContainGluten(), cake.getCakeType().c_str());
}
