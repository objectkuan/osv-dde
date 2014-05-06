#ifndef __LINUX_U64_STATS_SYNC_H__
#define __LINUX_U64_STATS_SYNC_H__

/**68**/ struct u64_stats_sync {
};
/*75*/ void u64_stats_update_begin(struct u64_stats_sync * a);
/*82*/ void u64_stats_update_end(struct u64_stats_sync * a);
/*94*/ unsigned int u64_stats_fetch_begin(const struct u64_stats_sync * a);
/*107*/ bool u64_stats_fetch_retry(const struct u64_stats_sync * a, unsigned int b);

#endif
