ll ans = 0;
  REP(i, N) {
    REP(k, W + 1) {
      if(dp[i][k] == INF) continue;
      ans = max(ans, dp[i][k]);
    }
  }
  cout << ans << endl;