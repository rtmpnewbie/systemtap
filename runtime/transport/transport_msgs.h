/* SystemTap transport values */
enum
{
	STP_TRANSPORT_PROC = 1,
	STP_TRANSPORT_RELAYFS
};

/* stp control channel command values */
enum
{
	STP_BUF_INFO = 1,
	STP_SUBBUFS_CONSUMED,
        STP_REALTIME_DATA,
        STP_TRANSPORT_INFO,
	STP_START,
        STP_EXIT,
	STP_OOB_DATA,
};

/* control channel command structs */
struct buf_info
{
	int cpu;
	unsigned produced;
	unsigned consumed;
};

struct consumed_info
{
	int cpu;
	unsigned consumed;
};

struct transport_info
{
	unsigned buf_size;
	unsigned subbuf_size;
	unsigned n_subbufs;
	int transport_mode;
	int target;		// target pid
#if 0
	char cmd[256];		// cmd to process data
#endif
};

struct transport_start
{
	int pid;	// pid for streaming data
};

