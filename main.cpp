#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

string rm1, rm2;

int rm2val(const string& rm) {
	auto ret = int{ 0 };
	for (auto i = 0; i < rm.length(); ++i) {
		const auto& c = rm[i];
		if ('M' == c) {
			ret += 1000;
			continue;
		}

		if ('D' == c) {
			ret += 500;
			continue;
		}

		if ('C' == c) {
			if (i < rm.length() - 1) {
				const auto& d = rm[i + 1];

				if ('M' == d) {
					ret += 900;
					++i;
					continue;
				}

				if ('D' == d) {
					ret += 400;
					++i;
					continue;
				}
			}

			ret += 100;
			continue;
		}

		if ('L' == c) {
			ret += 50;
			continue;
		}

		if ('X' == c) {
			if (i < rm.length() - 1) {
				const auto& d = rm[i + 1];

				if ('C' == d) {
					ret += 90;
					++i;
					continue;
				}

				if ('L' == d) {
					ret += 40;
					++i;
					continue;
				}
			}

			ret += 10;
			continue;
		}

		if ('V' == c) {
			ret += 5;
			continue;
		}

		if ('I' == c) {
			if (i < rm.length() - 1) {
				const auto& d = rm[i + 1];

				if ('X' == d) {
					ret += 9;
					++i;
					continue;
				}

				if ('V' == d) {
					ret += 4;
					++i;
					continue;
				}
			}

			ret += 1;
			continue;
		}
	}

	return ret;
}

void val2rm(ostringstream& oss, int val) {
	if (1000 <= val) {
		oss << 'M';
		val2rm(oss, val - 1000);
		return;
	}

	if (900 <= val) {
		oss << "CM";
		val2rm(oss, val - 900);
		return;
	}

	if (500 <= val) {
		oss << 'D';
		val2rm(oss, val - 500);
		return;
	}

	if (400 <= val) {
		oss << "CD";
		val2rm(oss, val - 400);
		return;
	}

	if (100 <= val) {
		oss << 'C';
		val2rm(oss, val - 100);
		return;
	}

	if (90 <= val) {
		oss << "XC";
		val2rm(oss, val - 90);
		return;
	}

	if (50 <= val) {
		oss << 'L';
		val2rm(oss, val - 50);
		return;
	}

	if (40 <= val) {
		oss << "XL";
		val2rm(oss, val - 40);
		return;
	}

	if (10 <= val) {
		oss << 'X';
		val2rm(oss, val - 10);
		return;
	}

	if (9 <= val) {
		oss << "IX";
		val2rm(oss, val - 9);
		return;
	}

	if (5 <= val) {
		oss << 'V';
		val2rm(oss, val - 5);
		return;
	}

	if (4 <= val) {
		oss << "IV";
		val2rm(oss, val - 4);
		return;
	}

	if (1 <= val) {
		oss << 'I';
		val2rm(oss, val - 1);
		return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> rm1 >> rm2;
	auto val1 = rm2val(rm1);
	auto val2 = rm2val(rm2);

	const auto ans = val1 + val2;
	cout << val1 + val2 << '\n';

	auto oss = ostringstream{};
	val2rm(oss, ans);

	cout << oss.str();

	return 0;
}