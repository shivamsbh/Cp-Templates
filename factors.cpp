	vi f;
	int alpha =;
	for ( int i = 1; i * i <= alpha; i++) {
		if (alpha % i == 0)
		{
			f.eb(i);
			if (i != alpha / i)
				f.eb(alpha / i);
		}
	}
	make_unique(f);
