#ifndef TEST_H
# define TEST_H

// clear all flags
# define CLEAR_ALL_FLAGS(f) (f & 0)

# define ADD_FLAG_MINUS(f) (f | 1)
# define ADD_FLAG_PLUS(f) (f | 2)
# define ADD_FLAG_SPACE(f) (f | 4)
# define ADD_FLAG_ZERO(f) (f | 8)
# define ADD_FLAG_HASH(f) (f | 16)

# define CLEAR_ALL_FLAGS(f) (f & 0)





typedef struct	s_list
{
	unsigned int		flags;

}				jst_param;

#endif
