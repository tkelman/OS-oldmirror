
import sys
import os
import re




#copied from COIN OR project TestTools
#see https://projects.coin-or.org/TestTools	
#------------------------------------------------------------------------
# Run an OS command in another process.
# Examples might be 'svn checkout', 'make test'.
# Return: command's return code, stdout messages, & stderr messages
#------------------------------------------------------------------------
def run(cmd) :

  if sys.version[:6]<'2.4.0' :

    # this machine has a back level of python, so must use an older
    # techniques to implement this function.  This implementation
    # runs the command in the same process as the script.
    # This has the problem that if the command crashes, it will bring
    # down the script. Another problem is that stderr and stdout are
    # mingled together

    import commands
    result = commands.getstatusoutput(cmd)
    retVal = { 'returnCode':result[0], 'stdout':result[1], 'stderr':'' }
    return retVal

  else :

    import subprocess
 
    p=subprocess.Popen(cmd,shell=True,\
                       stdout=subprocess.PIPE,\
                       stderr=subprocess.PIPE)
    cmdStdout,cmdStderr=p.communicate()
    cmdRc=p.returncode
    retVal = { 'returnCode':cmdRc, 'stdout':cmdStdout, 'stderr':cmdStderr }
    return retVal 



def visit(startDir, dirName, filesInDir):
	
	
	for fname in filesInDir:
		#we don't want files in svn folders
		if dirName.rfind(".svn") == -1 :
			fpath = os.path.join(dirName, fname);
			if fpath.rfind(".svn") == -1 :

				result = run('ls ' + dirName )
				if result['returnCode']==0 :
					print "successful run"
				else :
					print 'not succesfull for file ' +  fname
				
				


#os.path.walk('../data/osilFiles', visit, '.')

os.path.walk(sys.argv[ 1], visit, '.')


result = run('ls' )
if result['returnCode']==0 :
	print "successful run"
else :
	print "not succesfull"


