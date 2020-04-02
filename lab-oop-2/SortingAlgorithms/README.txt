Code Example

Sorting<int>* sorting = new ShellSort<int>(new CiuraStrategy());
vector<int> v = getRandomVector(0, 100, 50);
sorting->setComparator([](int const &left, int const &right) { return left < right; });
sorting->sort(v, 0, v.size() - 1);
