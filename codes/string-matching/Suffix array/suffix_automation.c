// bsublen -> best substring length till found
// bsubpos -> best substring starting position 

#include <string.h>
#include <stdio.h>

#define MAXN 250052
#define K 26

struct state {
	int len;
	int link;
	int next[K];
} st[MAXN << 1];

int size = 0;
int last = 0;
char str1[MAXN], str2[MAXN];

void init() {
	st[0].len = 0;
	st[0].link = -1;
	memset(st[0].next, -1, sizeof(st[0].next));
	size++;
}

void build_dfa(char c) {
	int nlast = size++, p, q, copy;
	
	st[nlast].len = st[last].len + 1;
	memset(st[nlast].next, -1 , sizeof(st[nlast].next));

	for(p = last; p != -1 && st[p].next[c] == -1 ; p = st[p].link) {
		st[p].next[c] = nlast;}
	
	if( p == -1) 
		st[nlast].link = 0;
	else {
		q = st[p].next[c];
		if(st[p].len + 1 == st[q].len) st[nlast].link = q;
		else { 
			copy = size++;
			st[copy].len = st[p].len + 1;
			memcpy(st[copy].next, st[q].next , sizeof(st[copy].next));
			st[copy].link = st[q].link;
			
			for(; p != -1 && st[p].next[c] == q; p = st[p].link ) {
				st[p].next[c] = copy; }
	
			st[q].link = st[nlast].link = copy;
		}
	}
	last = nlast;
}

int lcs(char *a, char *b) {
	int i;
	int p;
	int length;
	int bsublen, bsubpos;

	init();
	for(i = 0; a[i]; i++) 
		build_dfa(a[i]-'a');

	p = 0, length = 0, bsublen = 0, bsubpos = 0; //Initialisation

	for(i = 0; b[i]; i++) {
		if(st[p].next[b[i]-'a'] == -1) {
			for(; p != -1 && st[p].next[b[i]-'a'] == -1; p = st[p].link);

			if (p == -1) {
				p  = 0;
				length = 0; // Reset
				continue;
			}

			length = st[p].len;
		}

		p = st[p].next[b[i]-'a'];
		length++;
		
		if( length  > bsublen ) {
			bsublen = length;
			bsubpos = i;
		}
	}
	return bsublen;
}

int main()
{
	scanf("%s %s", str1, str2);
	printf("%d\n", lcs(str1, str2));
	return 0;
}		
