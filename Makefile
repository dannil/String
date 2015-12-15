# Environment 
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin


# build
build: .build-post

.build-pre:
# Add your pre 'build' code here...

.build-post: .build-impl
# Add your post 'build' code here...


# clean
clean: .clean-post

.clean-pre:
# Add your pre 'clean' code here...

.clean-post: .clean-impl
# Add your post 'clean' code here...


# clobber
clobber: .clobber-post

.clobber-pre:

.clobber-post: .clobber-impl


# all
all: .all-post

.all-pre:

.all-post: .all-impl


# build tests
build-tests: .build-tests-post

.build-tests-pre:

.build-tests-post: .build-tests-impl


# run tests
test: .test-post

.test-pre: build-tests

.test-post: .test-impl


# help
help: .help-post

.help-pre:

.help-post: .help-impl


# include project implementation makefile
include nbproject/Makefile-impl.mk

# include project make variables
include nbproject/Makefile-variables.mk