package spoopy.backend;

import spoopy.display.WindowStage;
import spoopy.backend.SpoopyCFFI;
import lime.ui.Window;

@:access(lime.ui.Window)
@:access(spoopy.display.WindowStage)
@:access(spoopy.SpoopyDevice)
class WindowRenderer {
    public var handle:Dynamic;

    var parent:WindowStage;

    public function new(parent:WindowStage) {
        this.parent = parent;
    }

    public function getWindowTitle(window:Window):String {
        #if (cpp && !cppia)
        if(window.__backend.handle != null) {
            return SpoopyCFFI.spoopy_window_get_title(window.__backend.handle);
        }
        #end

        return "";
    }

    /*
    public function applyWindowSurface(device:SpoopyDevice):Void {
        #if !(air && js && html5 && flash)
        if(parent.parent.__backend.handle != null && device.__manager.handle != null) {
            
        }
        #end
    }
    */
}