--- source/blender/collada/DocumentImporter.cpp.orig	2018-12-03 07:38:07 UTC
+++ source/blender/collada/DocumentImporter.cpp
@@ -1340,6 +1340,11 @@ bool DocumentImporter::writeAnimationLis
 	return anim_importer.write_animation_list(animationList);
 }
 
+bool DocumentImporter::writeAnimationClip(const COLLADAFW::AnimationClip *AnimationClip)
+{
+	return true;
+}
+
 /** When this method is called, the writer must write the skin controller data.
  * \return The writer should return true, if writing succeeded, false otherwise.*/
 bool DocumentImporter::writeSkinControllerData(const COLLADAFW::SkinControllerData *skin)
