
%% Setup
% Single frame image aquisition
mycam=imaq.VideoDevice('winvideo');
% Define video format
mycam.VideoFormat='MJPG_640x480';
% Create a structure element
diskElem = strel('disk',3);

% Create a BlobAnanlysis object to calculate detected objects’ area, 
% centroid, major axis length and label matrix. 
hBlob = vision.BlobAnalysis('MinimumBlobArea',2000,'MaximumBlobArea',50000);

% Create VideoPlayer
vidPlayer = vision.DeployableVideoPlayer;

%% Run the algorithm in a loop
for i=1:500
    videoframe=step(mycam);
    I = rgb2hsv(videoframe);
    
    % Define thresholds for channel 1 based on histogram settings
    channel1Min = 0.476;
    channel1Max = 0.535;
    
    % Define thresholds for channel 2 based on histogram settings
    channel2Min = 0.486;
    channel2Max = 1.000;
    
    % Define thresholds for channel 3 based on histogram settings
    channel3Min = 0.257;
    channel3Max = 1.000;
    
    % Create mask based on chosen histogram thresholds
    BW = (I(:,:,1) >= channel1Min ) & (I(:,:,1) <= channel1Max) & ...
        (I(:,:,2) >= channel2Min ) & (I(:,:,2) <= channel2Max) & ...
        (I(:,:,3) >= channel3Min ) & (I(:,:,3) <= channel3Max);
    
    % Use morphological operations to remove disturbances
    Ibwopen = imopen(BW,diskElem);
    
    % Extract the blobs from the frame
    [areaOut,centroidOut,bboxOut] = step(hBlob,Ibwopen);
    
    % Draw a box around the detected objects
    Ishape = insertShape(videoframe,'Rectangle',bboxOut,'Linewidth',4);
    Itext = insertText(Ishape,[centroidOut(:,1) centroidOut(:,2)],sprintf('%0.5f , ',centroidOut(:,1),...
        centroidOut(:,2)));
    step(vidPlayer,Itext);
end

%% Cleanup
release(mycam)
release(hBlob)
release(vidPlayer)