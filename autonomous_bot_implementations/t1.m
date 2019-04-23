mycam=imaq.VideoDevice('winvideo');
mycam.VideoFormat='MJPG_640x480';
mycam.ReturnedDataType='uint8';
diskElem=strel('disk',3);
hBlob = vision.BlobAnalysis('MinimumBlobArea',2000,'MaximumBlobArea',50000);
vidPlayer = vision.DeployableVideoPlayer;
for i=1:500
    % Get the dimensions of the image.  numberOfColorBands should be = 3.
   % [rows, columns, numberOfColorBands] = size(mycam);
   % redChannel = mycam(:, :, 1);
    %level = graythresh(rgbImage);
   % binaryImage = im2bw(redChannel,level); %#ok<IM2BW>
   % binaryImage = bwareaopen(binaryImage, 20000);
    %binaryImage = ~bwareaopen(~binaryImage, 20000);
   % [labeledImage, numberOfBlobs] = bwlabel(binaryImage, 8);  
                % Label each blob so we can make measurements of it
    %fprintf('Found %d blobs.\n', numberOfBlobs);
   % coloredLabels = label2rgb (labeledImage, 'hsv', 'k', 'shuffle'); 
                                  % pseudo random color labels
    % Measure the regions
    measurements = regionprops(mycam, 'Perimeter', 'Area');
    % Select certain blobs based using the ismember function.
    % Let's say that we wanted to find only those blobs
    % with a circularity more than 5 or so.
    allBlobPerimeters = [measurements.Perimeter];
    allBlobAreas = [measurements.Area];
    allCircularities = allBlobPerimeters .^ 2 ./ (4*pi*allBlobAreas);
    % Get a list of the blobs that meet our criteria and we need to keep.
    % keeperIndexes = find(allCircularities < 1.5)
    [~,keeperIndexes] = min(allCircularities);
    % Extract only those blobs that meet our criteria, and
    % eliminate those blobs that don't meet our criteria.
    % Note how we use ismember() to do this.
    keeperBlobsImage = ismember(mycam, keeperIndexes);
    % Measure the regions, this time getting equivalent circular diameter and centroid.
    measurements = regionprops(logical(keeperBlobsImage), ...
      'Perimeter', 'Area', 'EquivDiameter', 'Centroid','BoundingBox');
    ecd = measurements.EquivDiameter;
    equivDiameter(k,lettre) = ecd;
    c = measurements.Centroid;
    centroid(k,lettre,:) = c;
    BoundingBox = [measurements.BoundingBox];
end
    release(mycam)
release(hBlob)
release(vidPlayer)
    