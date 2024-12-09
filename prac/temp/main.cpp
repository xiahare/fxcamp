
using namespace std;

int main() {
    vector<int> v = {1, 2, 3};
    cout << "Sum: " << accumulate(v.begin(), v.end(), 0) << endl;
    return 0;
}
