#ifndef DDE_BLOCK_H
#define DDE_BLOCK_H

#ifdef __cplusplus
extern "C" {
#endif

struct request;

void dde_add_disk(void *gd);
void dde_set_capacity(void *cppdev, unsigned long nr_sects);

void *dde_get_blk_cppdev(void);
void dde_blk_start_xmit(void *gendisk);
struct request *dde_fetch_request(void);
void dde_dequeue_request(struct request *req);
void dde_finish_request(struct request *req);

#ifdef __cplusplus
}
#endif

#endif /* ! DDE_BLOCK_H */
