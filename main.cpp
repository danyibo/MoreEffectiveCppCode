#include<iostream>


// 条款2
namespace item_2 {

	class Widget{
		 virtual void  V() {}
	};
	class SpecialWidget : public Widget{};

	void update(SpecialWidget* psw) {
	}

	void test() {
		SpecialWidget sw;
		const SpecialWidget& csw = sw;

		/// void item_2::update(item_2::SpecialWidget*)”: 无法将参数 1 从“const item_2::SpecialWidget * ”转换为“item_2::SpecialWidget * 
		// update(&csw); 
		update(const_cast<SpecialWidget*>(&csw));
		update((SpecialWidget*)(&csw));


		// 这根指针：指向的是基类
		// Widget* pw = new SpecialWidget;
		/// update(pw);


		Widget* pw;
		// update(dynamic_cast<SpecialWidget*>(pw));


		

	}

}


namespace item_3 {
	class BST {
	public:
		BST() : value(100) {

		}
		~BST() {

		}

		//int &operator[](int index) {
		//	return value[index];
		//}

	public:
		int value;
	};

	class BalanceBST : public BST {};

	std::ostream& operator<<(std::ostream& os, BST b) {
		os << b.value << " ";
		return os;
	}

	void printBSTArray(std::ostream& s, const BST array[], int numElem) {
		for (int i = 0; i < numElem; ++i) {
			s << array[i];
		}
	}


	void deleteArray(std::ostream& logStream, BST array[]) {
		logStream << "Delete array at address " << static_cast<void*>(array) << '\n';
		delete[] array;
	}

	void test() {
		BST BSTArray[10];
		printBSTArray(std::cout, BSTArray, 10);

		std::cout << std::endl;
		BalanceBST bBSTArray[10];
		printBSTArray(std::cout, bBSTArray, 10);
		
		std::cout << std::endl;
		BalanceBST* balTreeArray = new BalanceBST[50];
		deleteArray(std::cout, balTreeArray);

	}

}



int main() {
	item_3::test();
	return 0;
}