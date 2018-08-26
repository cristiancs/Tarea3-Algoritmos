#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
 
// dp[i][j] is going to store true if sum j is
// possible with array elements from 0 to i.
bool** dp;
typedef unordered_map<int, int> mapa;

void getCodigo(mapa& cod_peso, const vector<int>& v) {
	
	//cout << "codigos: "<<endl;
    for (int i = 0; i < v.size(); ++i) {
		mapa::iterator it = cod_peso.find(v[i]);
		//auto it = cod_peso.find(v[i]);
		//int num = it.second;
		cout << endl;
		for (auto it = cod_peso.begin(); it != cod_peso.end(); ++it) {
			cout << "peso: " << it->first << " || cod: " << it->second<<endl;
		}
        //printf("%d ", it->second);
		printf("%d ", v[i]);
	}
	cout << endl;
	/*cout << "pesos: "<<endl;
	for (int i = 0; i < v.size(); ++i) {
        printf("%d ", v[i]);
	}
	cout <<endl;
    printf("\n");*/
}
 
// A recursive function to print all subsets with the
// help of dp[][]. Vector p[] stores current subset.
void printSubsetsRec(mapa& cod_peso, int arr[], int i, int sum, vector<int>& p) {
    // If we reached end and sum is non-zero. We print
    // p[] only if arr[0] is equal to sun OR dp[0][sum]
    // is true.
    if (i == 0 && sum != 0 && dp[0][sum])
    {
        p.push_back(arr[i]);
        getCodigo(cod_peso, p);
        return;
    }
 
    // If sum becomes 0
    if (i == 0 && sum == 0)
    {
        getCodigo(cod_peso, p);
        return;
    }
 
    // If given sum can be achieved after ignoring
    // current element.
    if (dp[i-1][sum])
    {
        // Create a new vector to store path
        vector<int> b = p;
        printSubsetsRec(cod_peso, arr, i-1, sum, b);
    }
 
    // If given sum can be achieved after considering
    // current element.
    if (sum >= arr[i] && dp[i-1][sum-arr[i]])
    {
        p.push_back(arr[i]);
        printSubsetsRec(cod_peso, arr, i-1, sum-arr[i], p);
    }
}
 
// Prints all subsets of arr[0..n-1] with sum 0.
void printAllSubsets(mapa& cod_peso, int arr[], int n, int sum) {
    if (n == 0 || sum < 0)
       return;
 
    // Sum 0 can always be achieved with 0 elements
    dp = new bool*[n];
    for (int i=0; i<n; ++i) {
        dp[i] = new bool[sum + 1];
        dp[i][0] = true;
    }
 
    // Sum arr[0] can be achieved with single element
    if (arr[0] <= sum)
       dp[0][arr[0]] = true;
 
    // Fill rest of the entries in dp[][]
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < sum + 1; ++j)
            dp[i][j] = (arr[i] <= j) ? dp[i-1][j] ||
                                       dp[i-1][j-arr[i]]
                                     : dp[i - 1][j];
    if (dp[n-1][sum] == false)
    {
        printf("0\n");
        return;
    }
 
    // Now recursively traverse dp[][] to find all
    // paths from dp[n-1][sum]
    vector<int> p;
    printSubsetsRec(cod_peso, arr, n-1, sum, p);
}
 
// Driver code
int main()
{	
	int n_alimentos, k_cal_esperadas, id_alim, w_alim, i;
	while(cin >> n_alimentos >> k_cal_esperadas){
		mapa cod_peso;
		int array_w[n_alimentos];

		for (i = 0; i < n_alimentos; ++i) {
			cin >> id_alim >> w_alim;
			array_w[i] = w_alim;
			int w = w_alim;
			int id = id_alim;
			//cod_peso[w].insert(id);
			cod_peso.insert(pair<int, int>(w, id));
		}

		/*cout << "n_alimentos: " << n_alimentos << "  calorias a sum: "<< k_cal_esperadas<<endl;
		for (auto it = cod_peso.begin(); it != cod_peso.end(); ++it) {
			cout << "peso: " << it->first << " || cod: " << it->second<<endl;
		}*/
		printAllSubsets(cod_peso, array_w, n_alimentos, k_cal_esperadas);
		cout << endl;
	}
    return 0;
}