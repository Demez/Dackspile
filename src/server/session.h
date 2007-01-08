/*******************************************************************************

   Copyright (C) 2006, 2007 M.K.A. <wyrmchild@users.sourceforge.net>
   For more info, see: http://drawpile.sourceforge.net/

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.

*******************************************************************************/

#ifndef ServerSession_INCLUDED
#define ServerSession_INCLUDED

//#include "../shared/protocol.types.h"
#include "../shared/protocol.flags.h"
#include "../shared/protocol.defaults.h"

#include "../shared/memstack.h"

struct Session;
#include "user.h"

/* iterators */
typedef std::map<uint8_t, User*>::iterator session_usr_iterator;

#include <stdint.h>

// Session information
struct Session
	//: MemoryStack<Session>
{
	Session(uint8_t _id=protocol::null_user) throw()
		: id(_id),
		len(0),
		title(0),
		pw_len(0),
		password(0),
		mode(protocol::user_mode::None),
		limit(10),
		owner(protocol::null_user),
		width(0),
		height(0),
		syncCounter(0)
	{
		#ifndef NDEBUG
		std::cout << "Session::Session()" << std::endl;
		#endif
	}
	
	~Session() throw()
	{
		#ifndef NDEBUG
		std::cout << "Session::~Session()" << std::endl;
		#endif
		
		users.clear();
		
		delete [] title;
	}
	
	// Session identifier
	uint8_t id;
	
	// Title length
	uint8_t len;
	
	// Session title
	char* title;
	
	// Password length
	uint8_t pw_len;
	
	// Password string
	char* password;
	
	// Default user mode
	uint8_t mode;
	
	//! User limit
	uint8_t limit;
	
	// Session owner
	uint8_t owner;
	
	// Canvas size
	uint16_t width, height;
	
	// Subscribed users
	std::map<uint8_t, User*> users;
	
	// Users waiting sync.
	std::stack<User*> waitingSync;
	
	// Session sync in action.
	uint32_t syncCounter;
};

#endif // ServerSession_INCLUDED
