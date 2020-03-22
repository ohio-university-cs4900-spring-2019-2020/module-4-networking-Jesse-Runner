#pragma once

#include "GLView.h"
#include "irrKlang.h"
#include "NetMessengerClient.h"
#include "Model.h"
#include "WO.h"
using namespace irrklang;

namespace Aftr
{
   class Camera;

/**
   \class GLViewNewModule
   \author Scott Nykl 
   \brief A child of an abstract GLView. This class is the top-most manager of the module.

   Read \see GLView for important constructor and init information.

   \see GLView

    \{
*/


  
	   class Cone
	   {
	   public:
		   static Cone* New(Vector position = Vector(25, 25, 25), const std::string file = "../mm/models/cone.wrl") {
			   return new Cone(position, file);
		   }

		   void setPosition(float x, float y, float z) {
			   cone->setPosition(Vector(x, y, z));
		   };
		   void setPosition(Vector v) {
			   cone->setPosition(v);
		   };
		   Vector getPosition() {
			   return cone->getPosition();
		   };
		   WO* getWorldObject() {
			   return cone;
		   };

	   protected:
		   WO* cone;
		   Cone(Vector position = Vector(25, 25, 25), const std::string file = "../mm/models/cone.wrl") {
			   this->cone = WO::New(file, Vector(1, 1, 1), MESH_SHADING_TYPE::mstFLAT);
			   this->cone->setPosition(position);
		   }
	   };



class GLViewNewModule : public GLView
{
public:
   static GLViewNewModule* New( const std::vector< std::string >& outArgs );
   virtual ~GLViewNewModule();
   virtual void updateWorld(); ///< Called once per frame
   virtual void loadMap(); ///< Called once at startup to build this module's scene
   virtual void createNewModuleWayPoints();
   virtual void onResizeWindow( GLsizei width, GLsizei height );
   virtual void onMouseDown( const SDL_MouseButtonEvent& e );
   virtual void onMouseUp( const SDL_MouseButtonEvent& e );
   virtual void onMouseMove( const SDL_MouseMotionEvent& e );
   virtual void onKeyDown( const SDL_KeyboardEvent& key );
   virtual void onKeyUp( const SDL_KeyboardEvent& key );
   Cone* cone;

protected:
   GLViewNewModule( const std::vector< std::string >& args );
   virtual void onCreate(); 
   ISoundEngine* SoundEngine = nullptr; 
   WO* spider_model = nullptr;
   NetMessengerClient* client;
};

/** \} */

} //namespace Aftr