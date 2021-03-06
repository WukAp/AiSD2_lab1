#include "pch.h"
#include "CppUnitTest.h"
#include "../AiSD2_lab1/Map.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AiSD2lab1UnitTest{

	TEST_CLASS(AiSD2lab1UnitTest){
		
	public:

		TEST_METHOD(findNodeTest) {
			Map<int, int> map;

			Assert::IsFalse(map.findNode(1));
			Assert::IsFalse(map.findNode(2));
			Assert::IsFalse(map.findNode(3));
			Assert::IsFalse(map.findNode(8));

			map.insert(1, 11);
			Assert::IsTrue(map.findNode(1));
			Assert::IsFalse(map.findNode(2));
			Assert::IsFalse(map.findNode(3));
			Assert::IsFalse(map.findNode(8));

			map.insert(2, 22);
			Assert::IsTrue(map.findNode(1));
			Assert::IsTrue(map.findNode(2));
			Assert::IsFalse(map.findNode(3));
			Assert::IsFalse(map.findNode(8));

			map.insert(3, 33);
			Assert::IsTrue(map.findNode(1));
			Assert::IsTrue(map.findNode(2));
			Assert::IsTrue(map.findNode(3));
			Assert::IsFalse(map.findNode(8));

			map.removeNode(3);
			Assert::IsTrue(map.findNode(1));
			Assert::IsTrue(map.findNode(2));
			Assert::IsFalse(map.findNode(3));
			Assert::IsFalse(map.findNode(8));

			map.removeNode(2);
			Assert::IsTrue(map.findNode(1));
			Assert::IsFalse(map.findNode(2));
			Assert::IsFalse(map.findNode(3));
			Assert::IsFalse(map.findNode(8));

			map.removeNode(1);
			Assert::IsFalse(map.findNode(1));
			Assert::IsFalse(map.findNode(2));
			Assert::IsFalse(map.findNode(3));
			Assert::IsFalse(map.findNode(8));
		}
		TEST_METHOD(insertTest){
			Map<int, int> map;

			map.insert(1, 11);
			map.insert(2, 22);
			map.insert(3, 33);

			Assert::IsTrue(map.findNode(1));
			Assert::IsTrue(map.findNode(2));
			Assert::IsTrue(map.findNode(3));
			Assert::IsFalse(map.findNode(8));
			Assert::IsFalse(map.findNode(9));
			Assert::IsFalse(map.findNode(10));


			map.insert(8, 11);
			map.insert(9, 22);
			map.insert(10, 33);
			Assert::IsTrue(map.findNode(1));
			Assert::IsTrue(map.findNode(2));
			Assert::IsTrue(map.findNode(3));
			Assert::IsTrue(map.findNode(8));
			Assert::IsTrue(map.findNode(9));
			Assert::IsTrue(map.findNode(10));
		}

		TEST_METHOD(clearTest){
			Map<int, int> map;

			map.insert(1, 11);
			map.insert(2, 22);
			map.insert(3, 33);
			Assert::IsTrue(map.findNode(1));
			Assert::IsTrue(map.findNode(2));
			Assert::IsTrue(map.findNode(3));

			map.clear();
			Assert::IsFalse(map.findNode(1));
			Assert::IsFalse(map.findNode(2));
			Assert::IsFalse(map.findNode(3));
		}

		TEST_METHOD(getKeysTest){
			Map<int, int> map;

			map.insert(1, 11);
			map.insert(2, 22);
			map.insert(3, 33);
			List <int> list = map.getKeys();

			Assert::IsTrue(list.at(0) == 1 || list.at(1) == 1 || list.at(2) == 1);
			Assert::IsTrue(list.at(0) == 2 || list.at(1) == 2 || list.at(2) == 2);
			Assert::IsTrue(list.at(0) == 3 || list.at(1) == 3 || list.at(2) == 3);
		}

		TEST_METHOD(getValuesTest){
			Map<int, int> map;

			map.insert(1, 11);
			map.insert(2, 22);
			map.insert(3, 33);
			List<int> list = map.getValues();

			Assert::IsTrue(list.at(0) == 11 || list.at(1) == 11 || list.at(2) == 11);
			Assert::IsTrue(list.at(0) == 22 || list.at(1) == 22 || list.at(2) == 22);
			Assert::IsTrue(list.at(0) == 33 || list.at(1) == 33 || list.at(2) == 33);
		}

		TEST_METHOD(removeNodeTest){
			Map<int, int> map;


			map.insert(1, 11);
			map.insert(2, 22);
			map.insert(3, 33);

			map.removeNode(3);
			Assert::IsTrue(map.findNode(1));
			Assert::IsTrue(map.findNode(2));
			Assert::IsFalse(map.findNode(3));
			Assert::IsFalse(map.findNode(8));

			map.removeNode(2);
			Assert::IsTrue(map.findNode(1));
			Assert::IsFalse(map.findNode(2));
			Assert::IsFalse(map.findNode(3));
			Assert::IsFalse(map.findNode(8));

			map.removeNode(1);
			Assert::IsFalse(map.findNode(1));
			Assert::IsFalse(map.findNode(2));
			Assert::IsFalse(map.findNode(3));
			Assert::IsFalse(map.findNode(8));
		}
	};
}
