Class Sorting is an abstract template class, which contains pure abstract method sort(). Subclasses implement different sorting algoritms.
For some of them there are implemented different strategies of sorting. QuickSort contains PivotingStrategy and ShellSort contains GappingStrategy.
You should choose a concrete strategy while creating an object of these classes.
Also, Sorting class contains a pure abstract method clone(). It implements Prototype pattern, so you can easily clone some Sorting object 
with all inner configurations.
Besides, you can change a comparator (it is a field of Sorting class). By default, all algorithms sort vector in an ascending order.
NOTE: you can sort only std::vector.


Code Example

Sorting<int>* sorting = new ShellSort<int>(new CiuraStrategy());
vector<int> v = getRandomVector(0, 100, 50);
sorting->setComparator([](int const &left, int const &right) { return left < right; });
sorting->sort(v, 0, v.size() - 1);
