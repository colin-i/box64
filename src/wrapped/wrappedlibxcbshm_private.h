#if !(defined(GO) && defined(GOM) && defined(GO2) && defined(DATA))
#error meh!
#endif

GO(xcb_shm_attach, pFpuuC)
GO(xcb_shm_attach_checked, pFpuuC)
GO(xcb_shm_attach_fd, pFpuuC)
GO(xcb_shm_attach_fd_checked, pFpuuC)
GO(xcb_shm_create_pixmap, pFpuuWWCuu)
GO(xcb_shm_create_pixmap_checked, pFpuuWWCuu)
GO(xcb_shm_create_segment, pFpuuC)
GO(xcb_shm_create_segment_reply, pFpup)
GO(xcb_shm_create_segment_reply_fds, pFpp)
GO(xcb_shm_create_segment_unchecked, pFpuuC)
GO(xcb_shm_detach, pFpu)
GO(xcb_shm_detach_checked, pFpu)
GO(xcb_shm_get_image, pFpuwwWWuCuu)
GO(xcb_shm_get_image_reply, pFpup)
GO(xcb_shm_get_image_unchecked, pFpuwwWWuCuu)
DATA(xcb_shm_id, 8)
GO(xcb_shm_put_image, pFpuuWWWWWWwwCCCuu)
GO(xcb_shm_put_image_checked, pFpuuWWWWWWwwCCCuu)
GO(xcb_shm_query_version, pFp)
GO(xcb_shm_query_version_reply, pFpup)
GO(xcb_shm_query_version_unchecked, pFp)
GO(xcb_shm_seg_end, pFpii)
GO(xcb_shm_seg_next, vFp)
