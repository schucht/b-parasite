#ifndef _PRST_MACROS_H_
#define _PRST_MACROS_H_

#define PRST_STRINGIFY(x) #x
#define PRST_TO_STRING(x) PRST_STRINGIFY(x)
#define PRST_LOCATION __FILE__ ":" PRST_TO_STRING(__LINE__)

#define RET_IF_ERR_MSG(expr, msg)                  \
  {                                                \
    int err = (expr);                              \
    if (err) {                                     \
      LOG_ERR("Error: " msg " in " PRST_LOCATION); \
      return err;                                  \
    }                                              \
  }

#define RET_IF_ERR(expr) RET_IF_ERR_MSG(expr, "")

// Checks that expr evaluates to true, otherwise return 1.
#define RET_CHECK(expr, msg) RET_IF_ERR_MSG(!(expr), msg)

#define UNUSED_OK(expr) (void)expr;

#ifndef CONFIG_PRSTLIB_DEFAULT_LOG_LEVEL
#define CONFIG_PRSTLIB_DEFAULT_LOG_LEVEL LOG_LEVEL_WRN
#endif

#endif  // _PRST_MACROS_H_