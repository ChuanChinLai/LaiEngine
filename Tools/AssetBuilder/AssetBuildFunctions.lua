
-- Environment Variables
local EngineSourceContentDir, GameInstallDir, ExternalDir, SDLBinDir

do
	-- EngineSourceContentDir
	do
		local errorMessage
		EngineSourceContentDir, errorMessage = GetEnvironmentVariable( "EngineSourceContentDir" )
		if not EngineSourceContentDir then
			error( errorMessage )
		end
	end

	-- GameInstallDir
	do 
		local errorMessage
		GameInstallDir, errorMessage = GetEnvironmentVariable("GameInstallDir")

		if not GameInstallDir then 
			error(errorMessage)
		else
			CreateDirectoryIfItDoesntExist( GameInstallDir )
		end
	end

	-- External Dir
	do 
		local errorMessage
		ExternalDir, errorMessage = GetEnvironmentVariable("ExternalDir")
		if not ExternalDir then 
			error(errorMessage)
		end
	end
		
	-- Copy SDL .dll file
	do 
		local errorMessage
		SDLBinDir, errorMessage = GetEnvironmentVariable("SDLBinDir")

		if not SDLBinDir then 
			error(errorMessage)
		else
			local Files = GetFilesInDirectory( SDLBinDir )

			for i, File in ipairs( Files ) do
				local sourceFileName = File:sub( #SDLBinDir + 1 )

				local targetPath = GameInstallDir .. sourceFileName
				
				print( File ) 
				print( targetPath )

				local result, errorMessage = CopyFile(File, targetPath)

				if result then
					print( "Copied " .. sourceFileName )
				else
					OutputMessage( "The file couldn't be copied to \"" .. targetPath .. "\": " .. errorMessage )
				end
			end
		end
	end

	--Copy Font
	do
		local errorMessage

		local sourceFilePath = EngineSourceContentDir .. "Fonts\\"
		local builtPath = GameInstallDir .. "Fonts\\"

		CreateDirectoryIfItDoesntExist( builtPath )

		local Files = GetFilesInDirectory( sourceFilePath )

		for i, File in ipairs( Files ) do
			local sourceFileName = File:sub( #sourceFilePath + 1 )
			local targetPath = builtPath .. sourceFileName
				
			local result, errorMessage = CopyFile(File, targetPath)

			if result then
				print( "Copied " .. sourceFileName )
			else
				OutputMessage( "The file couldn't be copied to \"" .. targetPath .. "\": " .. errorMessage )
			end
		end
	end


	--Copy Textures
	do
		local errorMessage

		local sourceFilePath = EngineSourceContentDir .. "Textures\\"
		local builtPath = GameInstallDir .. "Textures\\"

		CreateDirectoryIfItDoesntExist( builtPath )

		local Files = GetFilesInDirectory( sourceFilePath )

		for i, File in ipairs( Files ) do
			local sourceFileName = File:sub( #sourceFilePath + 1 )
			local targetPath = builtPath .. sourceFileName
				
			local result, errorMessage = CopyFile(File, targetPath)

			if result then
				print( "Copied " .. sourceFileName )
			else
				OutputMessage( "The file couldn't be copied to \"" .. targetPath .. "\": " .. errorMessage )
			end
		end
	end


	--Copy Gameplay Assets
	do
		local errorMessage

		local sourceFilePath = EngineSourceContentDir .. "Gameplay\\"
		local builtPath = GameInstallDir .. "Gameplay\\"

		CreateDirectoryIfItDoesntExist( builtPath )

		local Files = GetFilesInDirectory( sourceFilePath )

		for i, File in ipairs( Files ) do
			local sourceFileName = File:sub( #sourceFilePath + 1 )
			local targetPath = builtPath .. sourceFileName
				
			local result, errorMessage = CopyFile(File, targetPath)

			if result then
				print( "Copied " .. sourceFileName )
			else
				OutputMessage( "The file couldn't be copied to \"" .. targetPath .. "\": " .. errorMessage )
			end
		end
	end

end