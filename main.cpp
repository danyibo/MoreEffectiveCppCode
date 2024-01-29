#include<iostream>


// ����2
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

		/// void item_2::update(item_2::SpecialWidget*)��: �޷������� 1 �ӡ�const item_2::SpecialWidget * ��ת��Ϊ��item_2::SpecialWidget * 
		// update(&csw); 
		update(const_cast<SpecialWidget*>(&csw));
		update((SpecialWidget*)(&csw));


		// ���ָ�룺ָ����ǻ���
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



namespace item_4{


	class EquipmentPice {
	public:
		EquipmentPice(int IDNumber) {}
	};

	void test() {

		
		// EquipmentPice bestPrice[10];  // �޷�����ɹ�������������û��Ĭ�ϵĹ��캯��
		// EquipmentPice* bestPrice = new EquipmentPice[10];  // �����������Ĵ��������һ��

		//typedef EquipmentPice* PEP;
		//PEP bestPrice[10];
		//PEP* pBestPrice = new PEP[10];

		//�����㹻�Ŀռ�
		void* rawMemory = operator new[](10 * sizeof(EquipmentPice));
		EquipmentPice* bestPrices = static_cast<EquipmentPice*>(rawMemory);
		for (int i = 0; i < 10; ++i) {
			new (&bestPrices[i]) EquipmentPice(i);
		}
	}
}

int main() {
	item_3::test();
	return 0;
}